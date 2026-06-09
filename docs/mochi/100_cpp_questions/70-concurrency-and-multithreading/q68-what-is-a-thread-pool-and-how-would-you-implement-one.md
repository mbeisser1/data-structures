What is a thread pool and how would you implement one? #q68 #thread-pool #concurrency

---
A **thread pool** is a **managed group of threads** that efficiently process tasks in a multi-threaded environment — **reusing threads** instead of creating and destroying them for each task.

**Components:**

- **Work queue** — pending tasks
- **Worker threads** — wait, dequeue, execute
- **Synchronization** — mutex + condition variable
- **Lifecycle** — start/stop/shutdown

%%%MOCHI_CARD%%%
What is the worker loop pattern in a thread pool? #q68 #thread-pool #concurrency

---

- Workers **wait** on a condition variable when the queue is empty
- Under the mutex, **pop** a task and run it **outside** the lock
- **`notify_one`** when a task is enqueued; **`notify_all`** on shutdown

%%%MOCHI_CARD%%%
Show a thread-pool worker loop. How do workers wait for tasks and execute them safely? #q68 #thread-pool #concurrency

---
```cpp
workers.emplace_back([this] {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            condition.wait(lock, [this] { return stop || !tasks.empty(); });
            if (stop && tasks.empty())
                return;
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();  // run outside the lock
    }
});
```

%%%MOCHI_CARD%%%
How does `enqueue` return results from pool tasks? #q68 #thread-pool #concurrency

---

- Wrap work in **`std::packaged_task`**
- Return **`std::future`** to the caller before notifying a worker
- Worker runs the packaged task; caller blocks on **`future::get()`**

%%%MOCHI_CARD%%%
Show `enqueue` returning futures. How do you submit work to the pool and get a `future` back? #q68 #thread-pool #concurrency

---
```cpp
template<class F, class... Args>
auto enqueue(F&& f, Args&&... args)
    -> std::future<typename std::invoke_result<F, Args...>::type>
{
    using return_type = typename std::invoke_result<F, Args...>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace([task]() { (*task)(); });
    }
    condition.notify_one();
    return res;
}
```

%%%MOCHI_CARD%%%
What types are used in a typical thread pool implementation? #q68 #thread-pool #concurrency

---

- **`std::vector<std::thread>`** — workers
- **`std::queue<std::function<void()>>`** — task queue
- **`std::mutex`**, **`std::condition_variable`**, **`std::unique_lock`**
- **`std::atomic<bool>`** — stop flag
- **`std::future`** — async results to caller

Destructor: set **stop**, **notify_all**, **join** all workers.

%%%MOCHI_CARD%%%
In about 60 seconds, explain thread pools. #q68 #thread-pool #concurrency

---

- **Reuse threads** — amortize creation cost
- **Queue + workers + CV** — classic pattern
- **`enqueue` → future** for results
- Shut down cleanly: stop flag, wake all, join
