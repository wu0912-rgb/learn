#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable condition;
bool ready = false;  //标志位

void waiting_thread() {
    std::unique_lock<std::mutex> lock(mtx);  // 1. 获取锁

    // condition.wait() 的内部操作：
    condition.wait(lock, [] { return ready; });
    std::cout << "waiting_thread! Thread ID: "
        << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void trigger_thread() {
    std::unique_lock<std::mutex> lock(mtx);  // 1. 获取锁
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ready = true;
    condition.notify_all();
    std::cout << "trigger_thread! Thread ID: "
        << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread waitingthread(waiting_thread);  //等待线程
    std::thread triggerthread(trigger_thread);  //触发线程

    waitingthread.join();
    triggerthread.join();
    std::cout << "Hello World!\n";
}