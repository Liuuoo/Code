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

# RAII与智能指针
### RAII
这两个东西被称为现代c++的灵魂。为了解决内存泄漏和资源泄露的问题，c++引入了RAII的概念。即资源生命周期结束即释放。
现在有这样一份需求：
你需要编写一个类，确保文件在任何情况下都能被正确关闭。
- 类名： SafeFileHandler
- 私有属性：`FILE * fp`
- 构造函数：接收文件名和格式，"w"即fopen，注意异常的处理。
- 析构函数：检查fp是否为nullptr，如果是，则调用fclose并打印一份日志"resource is released safely"
- 核心工程约束：禁用拷贝 (Disable Copying)。 
    - 为什么？ 如果你把对象 A 拷贝给对象 B，它们都指向同一个文件。A 销毁时关了文件，B 销毁时会再次尝试关闭已经关闭的文件（Double Free/Close），这会导致程序崩溃。
    - 这项是AI给出的，我没太理解意思，但是我开始写代码，然后让AI给我诊断问题。

```cpp
#pragma once
#include<iostream>
#include<string>
namespace myFileHander
{
    class SafeFileHander
    {
    private:
        FILE * fp;
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
```

实际上c++的RAII就是使用C++析构函数在类生命周期结束时，会进行执行这一特性，完成的。
然后我们上面有个疑问：核心工程约束：禁用拷贝 (Disable Copying)。 这是因为如果不禁用拷贝（这边指的是=的浅拷贝，实际上c++也很难做到深拷贝），那么当一个类结束时并且释放了资源地址时，另外一个类中的指针并没有进行更改，这就导致了又重新释放一次指针。但是当前指针地址已经被释放了，再次释放很可能导致程序崩溃。这边来进行详细的说明：
### 栈和堆
栈，用完即销毁。析构函数就是销毁前一定要做的事情。
堆，空间非常大，我们调用的指针存放的就是堆空间的地址。不会自动销毁，因为自动销毁需要太多资源，效率不高。于是我们要注销堆上的东西时，需要手动处理，如`fclose()`。
但是当一个堆上的东西已经被处理过了，再进行销毁时，程序很有可能崩溃。
所以为了防止这样重复清理导致程序崩溃发生，我们一般禁止拷贝，或者使用引用计数（后续智能指针会学习）。
### 销毁/资源的释放
- 实际上在进行销毁和资源释放时，我们不是将数据给初始化或者擦去，而是将权限归还于操作系统。
- 操作系统会划出一大块内存空间作为程序运行可分配的安全空间。这部分空间一般不会于操作系统起冲突。
- 当我们申请一个地址，将地址存到指针中时，操作系统会将权限给我们。我们可以任意操作这块小的空间。操作系统会记录该空间不能再次进行分配。
- 当我们不需要使用时，我们申请释放资源，实际上就是将操作权限还给操作系统。操作系统记录可分配当前空间。然后也许很不巧就分配出去了。
- 所以当我们再次释放时，操作系统又会回收一次该权限。导致程序崩溃。流程可以这样：

1. 你销毁了 101。
2. 程序里的另一个模块（比如处理图片的模块）申请内存，操作系统把刚空出来的 101 分给了它。
3. 你又执行了一次销毁（重复销毁）。
4. 操作系统以为你在销毁你的东西，结果把图片模块正在使用的 101 强行收回了。
5. 图片模块再次访问 101 时，发现内存权被回收了，或者数据被弄乱了，程序瞬间崩溃。

然后 `SafeFileHander(const SafeFileHander&) = delete;`就申明，该类不能进行浅拷贝，编译器遇到=就会报错。

### 智能指针
实际上智能指针的作用就是不让我们自己写析构函数与delete，因为确实有很多人会忘记写。

#### std::unique_ptr
工程中常用的智能指针，拥有对资源的唯一所有权。
**不可拷贝：** 通过禁用内部构造函数，保证同一时间只能有一个指针指向这块内存。
**自动释放：** 应该是在析构函数中加入了释放，当unique_ptr离开作用域时，会自动释放，这边调用delete释放资源，而不是先前示例中的fclose。
**零开销：** 性能和裸指针几乎一样。

##### 使用
```cpp
#include <memory>
#include <iostream>

void unique_demo()
{
    // 推荐写法：创建并管理一个 int (42) 资源
    auto p1=std::make_unique<int> (42);
    std::cout<<*p1<<std::endl;
    // 不需要额外的释放
}
```
##### 所有权转移（std::move）
如果我们想将资源转移给别人，但禁止了拷贝，所以这边使用了move方法。
```cpp
void take_ownership(std::unique_ptr<int> p) {
    std::cout << "我拿到了资源: " << *p << std::endl;
} // 资源在这里被销毁！

void move_demo() {
    auto p1 = std::make_unique<int>(100);
    
    // take_ownership(p1); // 报错！禁止拷贝
    
    // 正确做法：使用 std::move
    take_ownership(std::move(p1)); 
    
    // 此时 p1 已经变为空指针了，这是安全的
    if (!p1) {
        std::cout << "p1 现在变空了。" << std::endl;
    }
}
```
这个move需要理解一下，在编译器眼中，所有对象都可以归结于两种。一种是左值，另一种右值。
左值是有持久身份的对象(int a)，右值是零时的没有身份的中间结果，如(a+b)。实际上可以理解为=右侧的。

然后还有c++11的一个新特性就是`&&`右值引用。使用这个，就可以引用一个右值。比如我可以这样写：
```cpp
void func(const int&& x);

func(10); // 10 是一个字面量（右值）
```
他就能识别出来。

然后move的作用就是强制类型转化，将左值强转为右值。于是我们可以这要操作：
```cpp
class BigData {
public:
    int* data;
    size_t size;

    // 1. 拷贝构造函数 (接收左值引用)
    BigData(const BigData& other) {
        this->size = other.size;
        this->data = new int[other.size]; // 分配新空间
        std::copy(other.data, other.data + size, this->data); // 复制内容
    }

    // 2. 移动构造函数 (接收右值引用)
    BigData(BigData&& other) noexcept {
        this->data = other.data;  // 直接接管别人的指针！
        this->size = other.size;
        
        other.data = nullptr;     // 把别人的指针置空，防止他析构时把这块内存删了
        other.size = 0;
    }
};
int main()
{
    BigData b = std::move(a);
}
```

该程序非常有意思，当函数销毁时，p的生命周期也结束。由于p是智能指针，会跟着销毁，所以这边能非常安全的释放当前资源。

##### vector
vector在创建时会在栈中开辟24个字节，放置三个指针，分别是：
-   **`begin`**：指向堆内存中数组的起始位置。

-   **`end`**：指向当前最后一个有效元素的下一个位置（即 `size` 的终点）。

-   **`end_of_storage`**：指向堆内存块的最末尾（即 `capacity` 的终点）。

当发现end==end_of_storage时，会进行扩容。一般是1.5/2倍。扩容很简单粗暴，是在堆上申请1.5/2倍空间。
- 如果元素标记``noexcept`就利用`move`将对象中的指针地址更换即可。旧指针就没用了。
- 如果发现不能，就只能一个一个的进行copy
然后释放旧地址上的资源。
然后更新栈上指针的地址，改为新的地址。

扩容时完整的生命周期是这样的：
-   **申请新空间**：在堆上开辟 1.5 倍的原始内存。

-   **移动构造（搬迁）**：

    -   在新内存位置调用 `unique_ptr` 的移动构造函数。

    -   新指针"偷"走地址，旧指针变 `nullptr`。

    -   **注意**：此时旧内存里躺着一个 `nullptr` 的 `unique_ptr` 对象。

-   **循环往复**：直到所有元素都完成搬迁。

-   **旧对象析构**：`vector` 遍历旧内存，对每一个旧元素调用析构函数。对于 `unique_ptr` 来说，析构一个 `nullptr` 是安全且无事的。

-   **释放旧内存**：最后调用 `operator delete` 把旧的整块空间还给系统。

#### std::shared_ptr
##### 介绍
有时候，一个资源需要被多个模块同时使用，这个时候我们使用`shared_ptr`，该指针内置一个计数器。当拷贝一次，计数+1，析构一次,计数-1。当计数-1后==0时，将资源释放。
##### 使用场景：
当你无法确定谁会是最后一个使用资源的人时，才考虑使用 `std::shared_ptr`。因为它有额外的计数器开销，所以性能略低于 `unique_ptr`。
##### 深入理解
该指针实际上是在对上面开辟了一块很小的空间，我们把该控件称之为控制块。一个控制块中维护两个数字：
1. 强引用计数：用于记录有多少个shared_ptr正在指向并使用这个资源
2. 弱引用计数：用于记录有多少个weak_ptr在观察这个资源。

##### 运作流程：

-   **当你拷贝一个 `shared_ptr` 时**：它只是简单地把那个控制块里的"强引用计数"数字 **$+1$**（这是一个原子操作，非常快）。

-   **当一个 `shared_ptr` 析构时**：它把数字 **$-1$**。

-   **最后一步**：如果减完之后数字变成了 **0**，那么当前的这个 `shared_ptr` 就会负责把数据和控制块一起销毁。
##### 问题
**1. 循环引用** 当程序出现循环引用时，比如A引用了B，B又引用了A,那么计数器永远无法降到0。
**2. 性能开销** 虽然快，但是不如unique_ptr快，所以非必要不使用。
##### 循环引用问题
我们这边再详细谈谈循环引用问题。

shared_ptr被释放的必要条件是计数器降到0。假设这边有一个shared_ptr p1\p2，他们共享指向一块相同的内存，此时计数器为2。

###### 1\. 核心解剖：`std::shared_ptr` 的真面目
你以为 `shared_ptr` 就是一个指针，但它在内存里其实是一对"双胞胎"。当你声明 `std::shared_ptr<Node> p` 时，栈上占用了 **2 个原始指针**的大小：

1.  **指向对象的指针**：用于访问你存储的数据（Node A）。

2.  **指向控制块的指针**：这才是实现"生死协议"的核心大脑。

**控制块里有什么**？

每个被 `shared_ptr` 管理的对象，在堆上都有一个唯一的控制块，包含：

-   **Strong Reference Count (强引用计数)**：决定对象何时销毁。

-   **Weak Reference Count (弱引用计数)**：决定控制块何时销毁。

-   **自定义删除器/分配器**等。

* * * *

###### 2\. 循环引用是如何"炼成"的？（底层步进）


我们用你最熟悉的 Node 结构，看看到底是怎么一步步把内存"锁死"的。

**第一步：创建独立的领地**


```
auto pA = std::make_shared<Node>();
auto pB = std::make_shared<Node>();

```

-   **栈内存**：产生 `pA` 和 `pB`。

-   **堆内存**：产生 **对象 A** 和其 **控制块 CA**，以及 **对象 B** 和其 **控制块 CB**。

-   **状态**：

    -   CA 的强引用计数 = 1（由 `pA` 持有）

    -   CB 的强引用计数 = 1（由 `pB` 持有）

**第二步：建立"死亡链接"**


```
pA->next = pB; // A 的成员变量 next（也是个 shared_ptr）指向了 B

```

-   这一步，**对象 B 的控制块 CB** 的强引用计数变成了 **2**（一个由栈上的 `pB` 持有，一个由堆上的 `A->next` 持有）。


```
pB->prev = pA; // B 的成员变量 prev（也是个 shared_ptr）指向了 A

```

-   这一步，**对象 A 的控制块 CA** 的强引用计数变成了 **2**（一个由栈上的 `pA` 持有，一个由堆上的 `B->prev` 持有）。

**第三步：栈的崩塌（函数结束）**

当函数执行完毕，栈内存被系统回收，`pA` 和 `pB` 消失。它们在消失前会履行最后的职责：**通知各自指向的控制块。**

1.  `pA` 消失：CA 的强引用计数 **$2 \\rightarrow 1$**。

2.  `pB` 消失：CB 的强引用计数 **$2 \\rightarrow 1$**。

由于pA仅仅只是个栈上的指针，虽然会随着弹出而被释放。但不是主体，所以NodeA中的next不会被释放，于是NodeB仍然被引用，NodeB->pre也不会释放。
#### std::weak_ptr
weak_ptr是shared_ptr的观察者模式。他只能有一个shared_ptr生成或者由一个weak_ptr生成。他的特点就是不增加引用计数。所以shared_ptr不记录weak_ptr的引用，所以能很好解决上述的循环引用问题。
之前提到，一个智能指针实际上是由两个指针组成。一个指针指向对象本身，另一个指针指向控制块。控制块中中比较复杂，但一定有强引用计数以及弱引用计数。
- 强引用计数：用来记录有多少个shared_ptr指向该控制块，**当它变为0时，对象销毁**，但该控制块
- 弱引用计数：用来记录有多少个weak_ptr指向该地址块并加1，1是指强引用计数本身对控制块的占用。当weak_ptr=0时，该控制块销毁。
  
weak_ptr不参与对象的生命周期，只参与控制块的生命周期。

这边有一个weak_ptr的用法示例：
```cpp
#include <iostream>
#include <memory>

int main() {
    auto shared = std::make_shared<int>(42);
    std::weak_ptr<int> weak = shared; // 指向它，但不拥有它

    // 检查对象是否还存在
    if (auto observed = weak.lock()) { // lock() 尝试获取一个 shared_ptr
        std::cout << "对象还在，值是: " << *observed << std::endl;
    } else {
        std::cout << "对象已经被销毁了" << std::endl;
    }

    shared.reset(); // 手动销毁对象

    if (weak.expired()) { // 也可以用 expired() 检查
        std::cout << "现在对象确实不在了" << std::endl;
    }
}
```

# 项目实战1：智能缓存管理器
补充了一些基础语法，然后了解了RAII、智能指针。这边我们让AI帮忙结合背景与所学列出了一些需求。然后我将会实现这些需求。
### 1\. 业务背景

假设你在开发一个类似你之前设计的"毛衫供应链管理系统"的桌面客户端。系统需要从磁盘加载大量的针织花样图片（Pattern）。

-   **痛点 1**：图片加载很慢，所以需要**缓存**（Cache）。

-   **痛点 2**：内存有限，如果某个图片现在没有任何页面在使用，它应该被**自动释放**。

-   **痛点 3**：如果多个模块同时请求同一张图片，它们应该**共享**同一个内存对象。

### 2\. 核心功能需求

-   **资源类 `Resource`**：

    -   模拟一个大型资源（可以是一个 `std::vector<char>`）。

    -   构造时打印 `"Loading resource [ID]..."`，析构时打印 `"Unloading resource [ID]..."`。

-   **管理器类 `ResourceManager`**：

    -   **接口 `get_resource(string id)`**：

        1.  如果缓存中有这个资源且有效，直接返回给调用者。

        2.  如果缓存中没有（或已失效），则加载资源，存入缓存并返回。

    -   **返回类型**：必须返回一个**智能指针**，让调用者可以安全使用。

### 3\. 硬核技术约束（这是精通的关键）

1.  **所有权控制**：

    -   调用者（各个功能模块）应该通过 `std::shared_ptr` 共同持有资源。只要还有一个模块在用，资源就不能消失。

2.  **非侵入式缓存 (`std::weak_ptr`)**：

    -   **核心挑战**：管理器内部的缓存字典（`std::map`）**不应该**增加资源的引用计数。

    -   **理由**：如果缓存也持有 `shared_ptr`，那么资源将永远不会被释放（因为缓存一直抓着它）。

    -   **要求**：缓存必须使用 `std::weak_ptr`。当最后一个外部 `shared_ptr` 销毁时，资源自动析构，此时缓存中的 `weak_ptr` 也会自动失效。

3.  **自动清理（清理死项）**：

    -   实现一个 `show_cache_status()` 函数，遍历缓存，打印哪些资源还活着，哪些已经变成了"空壳"。

### 4\. 验证场景

-   **场景 A（共享）**：模块 1 和模块 2 同时请求 `Pattern_A`，验证 `Loading` 只触发了一次，且引用计数变为 2。

-   **场景 B（释放）**：模块 1 和 2 依次销毁，验证 `Unloading` 在最后一个模块销毁时**立即触发**。

-   **场景 C（重载）**：资源被释放后，再次请求 `Pattern_A`，验证它会**重新加载**。

* * * *

### 为什么这个需求能让你精通？

这个任务逼迫你处理以下三个进阶问题：

1.  **打破循环/过度持有**：理解为什么缓存不能拥有所有权。

2.  **提升为 `shared_ptr`**：练习使用 `weak_ptr.lock()` 来安全地探测并临时获取资源。

3.  **线程安全性思考**（进阶）：虽然你可以先写单线程版，但你可以思考如果两个线程同时 `get_resource` 会发生什么。

**这个需求比 `FileHandler` 复杂得多，它涉及到对象之间的动态博弈。**

于是我写出了如下代码
```cpp
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
        if(cache.count(id))
        {
            auto weak_ptr=cache[id];
            if(auto observe=weak_ptr.lock())
            {
                std::cout<<"内存中捕获到"<<id<<"资源...\n";
                return observe;
            }
            else
            {
                std::cout<<"内存中曾经捕获...\n";
                // 需要创建一个资源，并将之放入set
                // Resource resource = Resource(id);
                auto shared_ptr=std::make_shared<Resource>(id);
                auto weak_ptr=std::weak_ptr<Resource>(shared_ptr);
                cache[id]=weak_ptr;
                return shared_ptr;
            }
        }
        else 
        {
            std::cout<<"内存中未捕获...\n";
            // 需要创建一个资源，并将之放入set
            // Resource resource = Resource(id);
            auto shared_ptr=std::make_shared<Resource>(id);
            auto weak_ptr=std::weak_ptr<Resource>(shared_ptr);
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
```
然后这边有很多重复臃肿的代码，然后AI给出了他的写法，非常优雅。值得学习
```cpp
std::shared_ptr<Resource> get_resource(std::string id)
    {
        auto &weak_ptr=cache[id]; // 注意这边使用引用
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
        }            
        return shared_ptr;
    }
```
非常优雅。