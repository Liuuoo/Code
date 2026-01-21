#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {   //这边注意是j>0,若是j==0数组会越界
        for(int j=n-1;j>0;j--) //两两相邻比较
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
        }
    }
    print(arr,n);
}

// 选择排序：每一轮找出最小的元素放到已排序序列末尾
void selection_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int max_index=i;
        for(int j=i;j<n;j++)// 在未排序部分中寻找更小的元素
        {
            if(arr[j]<arr[max_index])
            {
                max_index=j;
            }
        }
        swap(arr[i],arr[max_index]);
    }
    print(arr,n);
}

void insert_sort(int arr[],int n)
{
    for(int i=1;i<n;i++) //这边从1开始也可以，单个数本身有序
    {
        int key=arr[i]; // 当前要插入的元素
        int j=i-1;
        // 将大于当前元素的值向后移动一位，腾出插入位置
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key; // 插入当前元素到正确位置
    }
    print(arr,n);
}

int main()
{
    int arr[]={9,3,4,5,2,4,6,0};
    bubble_sort(arr,8);
    selection_sort(arr,8);
    insert_sort(arr,8);
}