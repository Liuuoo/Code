#include"ThreadPool.hpp"
void task()
{
    std::cout<<"hello\n";
}
int main()
{
    ThreadPool tp(5);
    tp.enqueue([]() {
    std::cout << "I am a lambda task running in thread " 
              << std::this_thread::get_id() << std::endl;
    });
}