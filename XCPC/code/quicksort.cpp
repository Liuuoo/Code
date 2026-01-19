#include <bits/stdc++.h>  // 包含所有常用标准库（常用于算法竞赛）
using namespace std;

// 待排序的数组
int a[] = {3, 4, 5, 1, 2, 6, 3};


/**
 * 分区函数：双向填坑法（基于基准值 a[l] 的快速排序分区）
 *
 * 原理：
 * 1. 选取 a[l] 作为基准值（pivot）
 * 2. 使用左右指针从两端向中间扫描
 * 3. 右边找小于 pivot 的元素，填到左边的“坑”（原 pivot 位置）后自己成为坑
 * 4. 左边找大于 pivot 的元素，填到右边的“坑”后自己成为坑
 * 5. 最终将 pivot 放入相遇位置（坑位）
 *
 * 特点：
 * - 不使用 swap，而是“填坑”方式移动元素
 * - 返回的是 pivot 的最终正确位置
 * - 分区后满足：[l, p-1] ≤ a[p] ≤ [p+1, r]
 *
 * @param l 左边界
 * @param r 右边界
 * @return 基准值（pivot）的最终下标位置
 */
int partition(int l, int r)
{
    int x = a[l];  // 选择最左侧元素作为基准值

    // 双向扫描，直到指针相遇
    while (l < r)
    {
        // 从右向左扫描，找到第一个小于基准值的元素
        while (l < r && a[r] >= x)
            r--;
        if (l < r)
        {
            a[l] = a[r];  // 将该元素填入左侧的“坑”
            l++;          // 左指针右移（当前 l 成为新的“坑”）
        }

        // 从左向右扫描，找到第一个大于基准值的元素
        while (l < r && a[l] <= x)
            l++;
        if (l < r)
        {
            a[r] = a[l];  // 将该元素填入右侧的“坑”
            r--;          // 右指针左移（当前 r 成为新的“坑”）
        }
    }

    // 此时 l == r，该位置是基准值的最终位置
    a[l] = x;  // 将基准值放入正确位置

    return l;  // 返回 pivot 的下标
}

/**
 * Lomuto 分区函数：单向扫描法
 *
 * 原理：
 * 1. 选取 a[r] 作为基准值（pivot）
 * 2. 维护一个边界 i，使得 [l, i] 内的元素都 ≤ pivot
 * 3. 遍历 j 从 l 到 r-1，将 ≤ pivot 的元素交换到左侧
 * 4. 最后将 pivot 与 a[i+1] 交换，使其归位
 *
 * 特点：
 * - 逻辑简单，易于理解
 * - 返回的是 pivot 的最终位置
 *
 * @param l 左边界
 * @param r 右边界
 * @return 基准值的最终下标位置
 */
int Lomuto_partition(int l, int r)
{
    int i = l - 1;        // i 指向“≤ pivot”区域的最后一个位置
    int x = a[r];         // 选择最右侧元素作为基准值

    // 遍历除 pivot 外的所有元素
    for (int j = l; j < r; j++)
    {
        if (a[j] <= x)  // 当前元素 ≤ pivot
        {
            swap(a[j], a[++i]);  // 将其交换到左侧区域
        }
    }

    // 将 pivot 放入正确位置
    swap(a[++i], a[r]);
    return i;  // 返回 pivot 的位置
}

/**
 * 快速排序主函数（递归实现）
 *
 * 步骤：
 * 1. 若区间无效（l >= r），直接返回
 * 2. 调用分区函数，将数组分为三部分：左 ≤ pivot ≤ 右
 * 3. 递归排序左右子数组
 *
 * 注意：
 * - 无论使用哪种分区方法，返回的 p 都是 pivot 的最终位置
 * - 因此递归调用为 [l, p-1] 和 [p+1, r]，**跳过已归位的 pivot**
 *
 * @param l 当前排序区间的左边界
 * @param r 当前排序区间的右边界
 */
void quick_sort(int l, int r)
{
    if (l >= r)  // 递归终止条件：区间为空或只有一个元素
        return;

    // 选择分区方法（任选其一）：
    
    // 方法1：使用 Lomuto 分区
    int p = Lomuto_partition(l, r);

    // 方法2：使用填坑法分区（取消注释即可）
    // int p = partition(l, r);

    // 递归排序 pivot 左右两部分
    quick_sort(l, p - 1);  // 排序左半部分 [l, p-1]
    quick_sort(p + 1, r);  // 排序右半部分 [p+1, r]
}

int main()
{
    quick_sort(0, 6); 
    for (int i = 0; i < 7; i++)
        cout << a[i];
    return 0;
}