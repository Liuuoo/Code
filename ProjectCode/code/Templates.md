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