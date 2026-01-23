#pragma once
#include<memory>
#include<map>
#include<string>
#include"Resource.hpp"
class auto_cahce_manager
{
private:
    std::map<std::string,std::weak_ptr<Resource> > cache;
public:
    auto_cahce_manager()
    {
        std::cout<<"管理器创建成功!\n";
    }
    std::shared_ptr<Resource> get_resource(std::string id)
    {
        auto weak_ptr=cache[id];
        auto shared_ptr=weak_ptr.lock();
        if(shared_ptr)
        {
            std::cout<<"内存中捕获到"<<id<<"资源...\n";
        }
        else 
        {
            std::cout<<"内存中未捕获...\n";
            // 需要创建一个资源，并将之放入set
            // Resource resource = Resource(id);
            shared_ptr=std::make_shared<Resource>(id);
            weak_ptr=std::weak_ptr<Resource>(shared_ptr);
            cache[id]=weak_ptr;
            return shared_ptr;
        }
    }
    ~auto_cahce_manager()
    {
        std::cout<<"资源全部释放,管理器退出...\n";
    }

    // auto_cahce_manager(const auto_cahce_manager&) = delete;
    // auto_cahce_manager &operator=(const auto_cahce_manager&) = delete;
};