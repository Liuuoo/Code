#include<iostream>
#include<limits>
#include<type_traits>
template<typename T> 

class Accumlator
{
private:
    T total_sum;
    int data_count;
    T max_val;
public:
    static_assert("该类仅支持能进行+-*/运算的数值的类型");
    // 使用初始化列表，效率更高
    Accumlator()
        :total_sum(0.0),
        data_count(0),
        max_val(std::numeric_limits<T>::lowest()){}
    void add(T value)
    {
        total_sum+=value;
        data_count++;
        max_val=std::max(max_val,value);
    }
    double getAverage() const // const表示该方法不会修改成员数据
    {
        if(data_count==0) 
        {
            std::cout<<"分母为0不能进行求平均值";
            return 0.0; //最好是抛出异常
        }
        else 
        {
            double avg=(double)total_sum / data_count;
            return avg;
        }
    }
    void reset()
    {
        // 工程提示：在类内部成员函数里，除非命名冲突，否则通常不加 this->
        data_count=0;
        max_val=INT_MIN;
        total_sum=0;
    }
    ~Accumlator()=default;
};

int main()
{
    Accumlator<int> a1;
    a1.add(10);
    std::cout<<a1.getAverage();
}