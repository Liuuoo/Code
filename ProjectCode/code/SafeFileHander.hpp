#pragma once
#include<iostream>
#include<string>
namespace myFileHander
{
    class SafeFileHander
    {
    private:
        FILE *fp;
    public:
        SafeFileHander(const std::string filename)
        {
            fp=std::fopen(filename.c_str(),"w");
            if(!fp)
            {
                throw std::runtime_error("无法打开文件："+filename);
            }
            else 
            {
                std::cout<<"文件正常打开\n";
            }
        }
        ~SafeFileHander()
        {
            if(fp!=nullptr)
            {
                fclose(fp);
                std::cout<<"resource is released safely!";
            }
        }

        SafeFileHander(const SafeFileHander&) = delete;
        SafeFileHander &operator=(const SafeFileHander&) = delete;


        void write(const std::string &text)
        {
            if(fp) 
            {
                std::fputs(text.c_str(), fp);
            }
        }
    };
}
