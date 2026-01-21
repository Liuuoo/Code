# 基础语法
## 类
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
## 模板
### 详细要求：

参数化类型： 使用 template <typename T>。

通用性： 类中的 total_sum、max_val 以及 add(T value) 的参数都应使用类型 T。

兼容性： 确保 getAverage() 依然返回 double（因为无论输入是整数还是浮点数，平均值通常都是小数）。

极值处理： 构造函数中的 max_val 需要使用 std::numeric_limits<T>::lowest() 来适配不同类型。

### 示例用法
```
Accumulator<int> intAcc;    // 统计整数
intAcc.add(10);
intAcc.add(20);

Accumulator<float> floatAcc; // 统计单精度浮点数
floatAcc.add(1.5f);
```

### 模板语法
如果没有模板，为了处理不同类型的数据，你需要写很多重复的代码：

add(int a, int b)

add(double a, double b)

有了模板，你只需写一个通用的公式，告诉编译器：“不管是什么类型 T，只要它支持 + 运算符，就按这个逻辑给我生成代码。”
```cpp
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
```
- template <...>：告诉编译器后面是一个模板。

- typename：表示 T 是一个类型。你也可以写成 class（即 template <class T>），在大多数情况下两者是等价的，但现代工程推荐使用 typename。

类模板 (Class Template)
```cpp
template <typename T> 
class Box
{
private:
    T data;
public:
    Box(T value) : data(value){}
    T getdata() const
    {
        return data;
    }
    ~Box() : default;
};
```
于是我们回过头将我们之前写的Accumlator改为模板：
```cpp
#include<iostream>
#include<limits>

template<typename T> 

class Accumlator
{
private:
    T total_sum;
    int data_count;
    T max_val;
public:
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
```
## 编译时断言
上面讲到了模板，我们发现模板非常好用。但是会出现一些未知问题。但有人调用我们的模板时，可能定义了：`Accumlator<string> a1;`，但我们知道这样的写法一定是会出现非常多的问题的。所以C++11引入一个新特性：编译时断言：用于防止我们的组件被乱用。
```cpp
#include <type_traits> // 必须包含这个库

template<typename T>
class Accumulator {
    // 语法：static_assert(条件, "错误提示文字");
    static_assert(std::is_arithmetic<T>::value, "Accumulator only supports numeric types!");
    
    // ... 其余逻辑 ...
};
```
static_assert 在编译阶段就会检查条件。如果不满足，它会给出你自定义的、人类可读的报错信息，而不是抛出一堆晦涩难懂的模板展开错误。

## 命名空间
命名空间的作用就是将写的代码围起来。这样，有不同的但是同样名字的类或者方法，编译器就可以通过命名空间的不同，进行识别。
```cpp
namespace my_project {
    template<typename T>
    class Accumulator {
        // ... 实现 ...
    };
}
```
在做工程时，永远不要在头文件的全局作用下写代码。通过命名空间，你告诉使用者：这是“我的”统计工具。使用者通过 `my_project::Accumulator` 来明确调用。

### 整合与总结
现在我们需要完成一个工程任务来总结以上的编译错误断言以及命名空间。当然这也是工程常用的一种形式。
**任务描述:**
- 需求 1： 使用 #ifndef 或 #pragma once 作为“头文件卫士”，防止被重复包含。
- 需求 2： 将整个类放在 namespace learn_cpp 中。
- 需求 3： 在类内部加入 static_assert 确保 T 是算术类型（整数或浮点数）。
- 需求 4： 将所有 C 风格的强制转换 (double) 改为 static_cast<double>()。

这边我遇到了不理解#ifndef与#pragma once的作用与用法，于是先学习。总结来讲，当编译器遇到两个相同头文件时，会报错重复定义头文件。例如：
假设你有三个文件：
- Tools.h: 定义了一个类 class Box {};
- Physics.h: 里面写了 #include "Tools.h"
- main.cpp: 里面写了 #include "Tools.h" 和 #include "Physics.h"
  
当编译器处理 main.cpp 时，它会展开所有的 include：
- 它先展开 Tools.h，看到了 class Box 的定义。
- 它再展开 Physics.h，而 Physics.h 又包含了 Tools.h，于是编译器第二次看到了 class Box 的定义。

结果： 编译器报错 error: redefinition of 'class Box'。这就像你在一份试卷上写了两遍完全一样的选择题答案，考官会判错。
**ifndef、define与endif:**
```cpp
#ifndef ACCUMULATOR_HPP  // 如果没定义这个名字的宏
#define ACCUMULATOR_HPP  // 那么立刻定义它

// ... 这里放你的类代码 ...

#endif // 结束判断
```
**#prama once**
这是一种简洁的指令，只需要在第一行写下这句即可。
```cpp
#pragma once

// ... 这里放你的类代码 ...
```
- 逻辑： 它直接告诉编译器：“这个文件，你今天只准给我读一次，不管谁再来 `include` 它，你都直接忽略。”

- 优点： 简单，不会出现宏名称冲突的问题。

一般来说现代工程使用prama once的形式。

学习了如何防止编译器读取两边头文件导致报错的问题之后，我们将原有代码进行拆分：

Accumlator.hpp:
```cpp
#pragma once
#include<iostream>
#include<limits>
#include<type_traits>
namespace MyAccumlator
{
    template<typename T> 
    class Accumlator
    {
    static_assert(std::is_arithmetic<T>::value,"Accumulator only supports numeric types!");
    private:
        T total_sum;
        int data_count;
        T max_val;
    public:
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

}
```
值得一提的是，先前的中文提示，在windows显示框中会乱码，即使终端切换为gbk也不行。所以最好是使用英文。
**main.cpp:**
```cpp
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
```