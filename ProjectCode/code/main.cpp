#include "Resource.hpp"
#include "auto_cahce_manager.hpp"

int main()
{
    auto manager=auto_cahce_manager();
    auto p1=manager.get_resource("1");
    auto p2=manager.get_resource("1");
    auto p3=manager.get_resource("2");
    auto p4=manager.get_resource("2");
}