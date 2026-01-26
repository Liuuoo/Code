#include<atomic>
#include<mutex>
#include<vector>
#include<thread>
#include<iostream>
int sum=0;
// std::atomic<int> g_counter(100);
int g_counter = 100;
std::mutex mtx;
void sale()
{
    while(true)
    {            
        {
            std::lock_guard<std::mutex> lg(mtx);
            if(g_counter!=0)
            {
                g_counter--;
                std::cout<<std::this_thread::get_id()<<"nd saled "<<g_counter+1<<" ticket successfully!\n";
            }
            else break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
int main()
{
    // std::cout<<g_counter<<'\n';
    std::vector<std::thread> vec(10);
    for(int i=0;i<10;i++)
    {
        vec[i]=(std::thread (sale));
    }
    int i=1;
    for(auto &x:vec)
    {
        if(x.joinable())x.join();
    }
    std::cout<<"nothing\n";
}