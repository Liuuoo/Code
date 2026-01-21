#include<bits/stdc++.h>
using namespace std;

// 待排序的数组 a，包含 7 个元素
int a[] = {3, 4, 5, 1, 2, 6, 3};

// 辅助数组 b，用于归并过程中临时存储排序后的结果
int b[100000];

// 归并函数：将区间 [l, mid] 和 [mid+1, r] 两个已排序的子数组合并成一个有序数组
void merge(int l, int mid, int r)
{
    int p = l, q = mid + 1;  // p 指向左半部分的起始位置，q 指向右半部分的起始位置
    for (int i = l; i <= r; i++)  // 遍历整个区间 [l, r]
    {
        // 条件判断：如果右半部分已经处理完（q > r），
        // 或者左半部分未处理完且当前左半部分元素小于等于右半部分元素
        if (q > r || (p <= mid && a[p] <= a[q]))
        {
            b[i] = a[p];  // 将左半部分的元素放入辅助数组
            p++;          // 左指针后移
        }
        else
        {
            b[i] = a[q];  // 否则将右半部分的元素放入辅助数组
            q++;          // 右指针后移
        }
    }
    // 将辅助数组 b 中合并好的结果复制回原数组 a
    for (int i = l; i <= r; i++)
    {
        a[i] = b[i];
    }
}

// 归并排序主函数：对区间 [l, r] 内的元素进行排序
void merge_sort(int l, int r)
{
    // 递归终止条件：如果区间只有一个元素（l == r），无需排序
    if (l == r) return;

    // 计算中点 mid，将区间分为两部分
    int mid = (l + r) / 2;

    // 递归排序左半部分 [l, mid]
    merge_sort(l, mid);

    // 递归排序右半部分 [mid+1, r]
    merge_sort(mid + 1, r);

    // 合并两个已排序的子区间
    merge(l, mid, r);

    return;  // 可省略，因为是 void 函数
}

int main()
{
    merge_sort(0, 6);
    for (int i = 0; i < 7; i++)
        cout << a[i];
    return 0;
}