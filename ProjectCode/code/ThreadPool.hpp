#pragma once
#include<thread>
#include<mutex>
#include<vector>
#include<condition_variable>
#include<functional>
#include<queue>
#include<iostream>
class ThreadPool
{
private:
    std::condition_variable cv;
    std::mutex mtx;
    std::queue<std::function<void()>> task_queue;
    bool stop=false;
    std::vector<std::thread> workers;
public:
    ThreadPool(int num)
    {
        for(int i=0;i<num;i++)
        {
            workers.emplace_back(&ThreadPool::work, this);
        }
        // std::thread(manager());
    }

    void work() noexcept
    {
        while(true)
        {
            std::unique_lock<std::mutex> ul(mtx);
            cv.wait(ul,[&]{
                return (stop||!task_queue.empty());
            });
            if(stop && task_queue.empty()) return;
            else
            {
                // operate
                auto fnt=std::move(task_queue.front());
                task_queue.pop();
                ul.unlock();
                std::cout<<"working...\n";
                fnt();
                // do zhe function
            }
        }
    }

    void enqueue(std::function<void()> f)
    {
        std::lock_guard<std::mutex> lg(mtx);
        task_queue.push(std::move(f));
        cv.notify_one();
    }

    ~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lg(mtx);
            stop=true;
        }
        cv.notify_all();
        for(auto &x: workers)
        {
            if(x.joinable()) x.join();
        }
    }
    ThreadPool(const ThreadPool&)=delete;
    ThreadPool &operator=(const ThreadPool&)=delete;
};