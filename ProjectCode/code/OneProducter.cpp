#include<thread>
#include<mutex>
#include<iostream>
#include<vector>
#include<queue>
#include<condition_variable>

std::mutex mtx;
bool empty=true;
std::queue<bool> q;
std::condition_variable cv;

void product()
{
    while(true) // 生产者这边仍然需要不停的进行生产
    {
        // 生产者1s产出一个
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
        // 生产完成，将之放入队列
        {
            std::cout<<"producter "<<std::this_thread::get_id()<<" make one!\n";
            std::lock_guard<std::mutex> lg(mtx);
            q.push(true);
        }
        cv.notify_one();
    }
}

void custome()
{
    while(true)
    {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul,[&]{return !q.empty();}); 
        q.pop();
        std::cout<<"customer "<<std::this_thread::get_id()<<" eat one!\n";
        ul.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 假设一个人吃0.5秒
    }
}

int main()
{
    std::thread producter1 (product);
    std::thread producter2 (product);
    std::vector<std::thread> customers;
    for(int i=0;i<10;i++)
    {
        customers.push_back(std::thread(custome));
    }
    producter1.join();
    producter2.join();
    for(auto &x:customers)
    {
        if(x.joinable()) x.join();
    }
}