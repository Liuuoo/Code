#include "Accumlator.hpp"

int main()
{
    MyAccumlator::Accumlator<int> A1;
    // MyAccumlator::Accumlator<std::string> A2;
    A1.add(10);
    std::cout<<A1.getAverage();
    // A2.add("abc");
    // std::cout<<A2.getAverage();
}