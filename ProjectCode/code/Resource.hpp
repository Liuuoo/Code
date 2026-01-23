#pragma once
#include<iostream>
class Resource
{
private:
    std::string id;
public:
    Resource(std::string id)
    {
        this->id=id;
        std::cout<<"Loading resource ["<<id<<"]...\n";
    }
    std::string getname()
    {
        return id;
    }
    ~Resource()
    {
        std::cout<<"Unloading resource ["<<id<<"]...\n";
    }
};
