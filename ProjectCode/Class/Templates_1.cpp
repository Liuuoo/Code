#include<iostream>
template <typename T>
T myMax(T a, T b)
{
    return (a>b) ? a:b;
}
int main()
{
    std::cout<< myMax(10,20);
    std::cout<< myMax(10.1,12.1);
}