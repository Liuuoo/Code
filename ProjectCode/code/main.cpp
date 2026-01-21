#include "SafeFileHander.hpp"

void test_rail()
{
    myFileHander::SafeFileHander safefilehander ("log.txt");
    safefilehander.write("这是第一行测试");

    bool has_error=true;
    // 这边模仿工程中出现的意外问题
    if(has_error)
    {
        std::cout<<"检查到意外逻辑，提前return\n";
        return;
    }
    safefilehander.write("cannot run this row");
}

int main()
{
    myFileHander::SafeFileHander safefilehander ("README.md");
    try
    {
        test_rail();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"程序继续运行\n";
}