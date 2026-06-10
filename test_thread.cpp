#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <exception>
#include <future>
#include <initializer_list>
#include <iostream>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <thread>
#include <vector>

namespace exceptional {
std::mutex g_mutex{};
std::vector<std::exception_ptr> g_exceptions;

void func1()
{
    throw std::runtime_error("exception 1");
}

void func2()
{
    throw std::runtime_error("exception 2");
}

void thread_func1()
{
    try
    {
        func1();
    }
    // catch (const std::runtime_error& e)
    // {
    //     std::lock_guard<std::mutex> lock{g_mutex};
    //     g_exceptions.push_back(std::make_exception_ptr(e));
    // }
    catch (...)
    {
        std::lock_guard<std::mutex> lock{g_mutex};
        g_exceptions.push_back(std::current_exception());
    }
}

void thread_func2()
{
    try
    {
        func2();
    }
    catch (const std::runtime_error& e)
    {
        std::lock_guard<std::mutex> lock{g_mutex};
        g_exceptions.push_back(std::make_exception_ptr(e));
    }
    // catch (...)
    // {
    //     std::lock_guard<std::mutex> lock{g_mutex};
    //     g_exceptions.push_back(std::current_exception());
    // }
}

void test_exceptional()
{
    std::thread t1{thread_func1};
    std::thread t2{thread_func2};
    t1.join();
    t2.join();

    for (const auto& e : g_exceptions)
    {
        try
        {
            if (e != nullptr)
            {
                std::rethrow_exception(e);
            }
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << "\n";
        }
    }
}

} // namespace exceptional

void func1()
{
    std::this_thread::yield();
    std::cout << "func1 no params" << "\n";
}

void func2(int a, int& b)
{
    std::cout << "func2" << "\n";
}

void dispatch3()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10000s);
}

void test_basic_thread()
{
    std::thread t; // nothing
    t = std::thread(func1);

    auto t1 = std::thread{[]() { std::cout << "thread t1\n"; }};

    int b = 7;
    auto t2 = std::thread{func2, 4, std::ref(b)};

    auto t3 = std::thread{dispatch3};

    t1.join();
    t2.join();
    t3.detach();
    t.join();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
std::mutex g_mutex{};
void thread_func()
{
    using namespace std::chrono_literals;
    {
        std::lock_guard<std::mutex> lock{g_mutex};
        std::cout << "running thread " << std::this_thread::get_id() << "\n";
    }

    std::this_thread::yield();
    std::this_thread::sleep_for(2s);

    {
        std::lock_guard<std::mutex> lock{g_mutex};
        std::cout << "done in thread " << std::this_thread::get_id() << "\n";
    }
}

void test_mutex()
{
    auto t1 = std::thread{thread_func};
    auto t2 = std::thread{thread_func};
    t1.join();
    t2.join();
}

template <typename T>
struct MyContainer
{
    MyContainer(std::initializer_list<T> i_list) : data_{i_list} {}
    std::mutex mutex_{};
    std::vector<T> data_;

    void printData(const std::string& message)
    {
        std::cout << message << "\n";
        std::for_each(data_.begin(), data_.end(), [](T value) { std::cout << value << " "; });
        std::cout << "\n";
    }
};

template <typename T>
void move_between(MyContainer<T>& c1, MyContainer<T>& c2, T value)
{
    // std::lock(t1.mutex_, t2.mutex_);
    std::scoped_lock lock(c1.mutex_, c2.mutex_);
    std::cout << "Looking for " << value << "\n";
    c1.printData("Before c1 erase");
    auto new_end = std::remove(c1.data_.begin(), c1.data_.end(), value);
    auto found = (new_end != c1.data_.end());

    c1.data_.erase(new_end, c1.data_.end());
    c1.printData("After c1 erase");

    if (found)
    {
        std::cout << "Found " << value << "\n";
        c1.printData("Before c2 erase");
        c2.data_.push_back(value);
        c1.printData("After c2 erase");
    }
    else
    {
        std::cout << "Skipping move\n\n";
    }
}

void test_container()
{
    auto c1 = MyContainer<int>{1, 2, 3};
    auto c2 = MyContainer<int>{5, 6, 7};
    move_between(c1, c2, 2);
    move_between(c1, c2, 4);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
namespace cv {

std::mutex mtx{};
std::condition_variable ready{};
std::queue<int> work{};
bool done = false;

void producer()
{
    for (int i = 1; i <= 5; ++i)
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);

        {
            std::lock_guard<std::mutex> lock{mtx};
            work.push(i);
            std::cout << "produced " << i << "\n";
        }
        ready.notify_one(); // wake one waiting consumer
    }

    {
        std::lock_guard<std::mutex> lock{mtx};
        done = true;
    }
    ready.notify_all(); // wake consumer so it can see done == true
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock{mtx};

        // wait until work is available OR producer finished
        ready.wait(lock, []() { return !work.empty() || done; });

        while (!work.empty())
        {
            const int value = work.front();
            work.pop();
            lock.unlock();
            std::cout << "consumed " << value << "\n";
            lock.lock();
        }

        if (done)
        {
            break;
        }
    }
}

void test_cv()
{
    std::thread producer_thread{producer};
    std::thread consumer_thread{consumer};
    producer_thread.join();
    consumer_thread.join();
}

} // namespace cv

///////////////////////////////////////////////////////////////////////////////////////////////////////
// promise/future: one-shot result transfer from a worker thread back to the caller.
// Unlike condition_variable, there is no shared queue — the future holds the value.
namespace pf {

int square_after_delay(int x)
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(200ms);
    if (x < 0)
    {
        throw std::runtime_error("negative input");
    }
    return x * x;
}

// Worker owns the promise (move-only). Caller keeps the matching future.
// set_value / set_exception may each be called at most once.
void worker(std::promise<int> result, int input)
{
    try
    {
        result.set_value(square_after_delay(input));
    }
    catch (...)
    {
        // Pack the active exception so future::get() can rethrow it in the caller thread
        result.set_exception(std::current_exception());
    }
}

void test_pf_success()
{
    std::promise<int> prom;
    // Link promise and future BEFORE moving prom into the worker thread
    std::future<int> fut = prom.get_future();

    std::thread t{worker, std::move(prom), 7};

    std::cout << "waiting for result...\n";
    // Blocks until set_value or set_exception; only call get() once per future
    const int answer = fut.get();
    std::cout << "7^2 = " << answer << "\n";

    t.join();
}

void test_pf_exception()
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread t{worker, std::move(prom), -3};

    std::cout << "waiting for error...\n";
    try
    {
        const int answer = fut.get(); // rethrows in *this* thread, not the worker
        std::cout << "unexpected: " << answer << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "caught: " << e.what() << "\n";
    }

    t.join();
}

} // namespace pf

///////////////////////////////////////////////////////////////////////////////////////////////////////
// std::async: shortcut for "run callable, return std::future" — no manual thread/promise wiring.
namespace async {

int square_after_delay(int x)
{
    using namespace std::chrono_literals;
    std::cout << "  computing on thread " << std::this_thread::get_id() << "\n";
    std::this_thread::sleep_for(200ms);
    if (x < 0)
    {
        throw std::runtime_error("negative input");
    }
    return x * x;
}

void test_async_launch()
{
    std::cout << "main thread id:     " << std::this_thread::get_id() << "\n";

    // launch::async — usually runs on a new thread soon after this line
    auto fut = std::async(std::launch::async, square_after_delay, 6);

    std::cout << "async launched — main can do other work before get()\n";
    const int answer = fut.get(); // block until result is ready
    std::cout << "6^2 = " << answer << "\n";
    // no join() — future from async manages the task lifetime
}

void test_async_deferred()
{
    std::cout << "main thread id:     " << std::this_thread::get_id() << "\n";

    // launch::deferred — callable does NOT run until get() or wait()
    auto fut = std::async(std::launch::deferred, square_after_delay, 5);

    std::cout << "deferred created — square_after_delay has NOT run yet\n";
    const int answer = fut.get(); // runs square_after_delay now, on this thread
    std::cout << "5^2 = " << answer << "\n";
}

void test_async_exception()
{
    auto fut = std::async(std::launch::async, square_after_delay, -2);

    std::cout << "waiting for async error...\n";
    try
    {
        const int answer = fut.get(); // exception rethrows in caller, like pf
        std::cout << "unexpected: " << answer << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "caught: " << e.what() << "\n";
    }
}

} // namespace async

int main()
{
    // test_mutex();
    // test_container();
    // exceptional::test_exceptional();
    // cv::test_cv();
    // pf::test_pf_success();
    // pf::test_pf_exception();
    async::test_async_launch();
    async::test_async_deferred();
    async::test_async_exception();
    return 0;
}
