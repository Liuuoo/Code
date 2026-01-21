1. 概述

    在开发大型软件（如数据库、后台服务器、数据分析引擎）时，我们经常需要对流式输入的数据进行统计（求和、求平均值、求最大值）。

    - 在工程中，如果程序其他地方不小心修改了 sum，或者在 count 为 0 时计算了平均值，程序就会产生不可预知的错误甚至崩溃

    - **解决方案** 创建一个 Accumulator 类，将数据（属性）和逻辑（方法）封装在一起。外部代码禁止直接修改内部数据，只能通过你提供的“安全接口”进行交互。

2. 具体实现：

    A. 属性
    - total_sum: 用于记录有所数据的总和(double)
    - data_count： 记录输入数据的个数(int)
    - max_val：记录输入数据中的最大值(double)

    B. 接口
    1. 构造函数：确保初始化时，total_sum和data_sum为0。
    2. void add(double value):
        - 向累加器中传入一个值
        - 更新总和、计数器和最大值
    3. double getAverage() const:
        - 逻辑安全的处理，不能在coun==0时进行。
    4. void reset()
        - 初始状态，重新统计。


一个很好的示例如下：
```cpp
#include<iostream>
#include<algorithm>
class Accumlator
{
private:
    double total_sum;
    int data_count;
    double max_val;
public:
    // 使用初始化列表，效率更高
    Accumlator()
        :total_sum(0.0),
        data_count(0),
        max_val(std::numeric_limits<double>::lowest()){}
    void add(double value)
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
            double avg=total_sum/data_count;
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
```