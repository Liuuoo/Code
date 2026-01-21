int a[]={1,2,3,4,5,6};
int find_use_index(int index,int max_size)
{
    if(index-1<0||index-1>=max_size) return -1; // 假设a数组都为正数
    return a[index-1];
}
int find_use_val(int val,int max_size)
{
    for(int i=0;i<max_size;i++)
    {
        if(a[i]==val)
        {
            return i;
        }
    }
    return -1; // 没找到
}
bool revise(int index, int val, int max_size)
{
    if(index-1 < 0 || index-1 >= max_size) return false; // 越界了，提前判断,修改不成功
    else
    {
        a[index-1]=val;
        return true; // 成功修改
    }
}
bool add(int index, int val, int now_size, int max_size)
{
    if(now_size>=max_size || index < 0 || index > max_size) return false;
    else 
    {
        for(int i=now_size;i>=index;i--)
        {
            a[i]=a[i-1];
        }
        a[index-1]=val;
        return true;
    }
}
bool del(int index,int val,int max_size)
{
    if(index<0) return false;
    for(int i=index;i<max_size-1;i++)
    {
        a[i]=a[i+1];
    }
    return true;
}