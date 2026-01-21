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
