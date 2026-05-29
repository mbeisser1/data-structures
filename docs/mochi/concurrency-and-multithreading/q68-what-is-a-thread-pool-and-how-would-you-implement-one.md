What is a thread pool and how would you implement one? #q68 #thread-pool #concurrency

---
A **thread pool** maintains a **fixed set of worker threads** that pull tasks from a **shared queue** — avoiding per-task thread create/destroy overhead.

**Components:**

- **Work queue** — pending tasks
- **Worker threads** — wait, dequeue, execute
- **Synchronization** — mutex + condition variable
- **Lifecycle** — start/stop/shutdown

%%%MOCHI_CARD%%%
What is the worker loop pattern in a thread pool? #q68 #thread-pool #concurrency

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

Workers **wait** when queue empty; **notify_one** when task enqueued.

%%%MOCHI_CARD%%%
How does `enqueue` return results from pool tasks? #q68 #thread-pool #concurrency

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

**`packaged_task` + `future`** bridges thread pool and caller.

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
