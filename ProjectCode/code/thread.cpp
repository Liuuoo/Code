#include<thread>
#include<iostream>
#include<vector>
#include<mutex>

std::mutex mtx;

void test_case(std::string name,int time)
{
    for(int i=0;i<time;i++)
    {
        {
            std::lock_guard<std::mutex> lock(mtx); 
            std::cout<<std::this_thread::get_id()<<" "<<name<<'\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        // 适当休眠
    }
}

int main()
{
    std::vector<std::thread> vec;
    for(int i=0;i<5000;i++)
    {
        vec.emplace_back(std::thread (test_case,std::to_string(i),i));
    }
    for(auto &x:vec)
    {
        if(x.joinable()) x.join();
    }
    std::cout<<"All work done!";
}
