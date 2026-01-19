#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Set 用于存储唯一元素并自动排序（红黑树实现）
    set<int> S;  // 初始化：O(1)

    // Map 用于存储键值对（这里记录每个数出现的次数）（红黑树实现）
    map<int, int> M;  // 初始化：O(1)

    // 输入处理
    for(int i = 0; i < n; ++i) {  // 循环 n 次
        int x;
        cin >> x;

        // 插入 set（自动去重）
        S.insert(x);  // 插入：O(log n)

        // 更新 map（统计出现次数）
        M[x]++;       // 插入/访问：O(log n)
    }

    cout << "==================\n";

    // 输出 set 中的元素（自动排序且无重复）
    cout << "集合中的元素（已排序且无重复）：";
    for (auto x : S) {  // 遍历：O(n)
        cout << x << " ";
    }
    cout << "\n\n";

    // 输出 map 中的键值对（按键排序）
    cout << "映射中的键值对（按键排序）：\n";
    for (auto x : M) {  // 遍历：O(n)
        cout << x.first << " => " << x.second << '\n';
    }
    cout << "\n";

    // 输出 set 中的最小和最大值
    if (!S.empty()) {
        cout << "集合中最小值：" << *S.begin() << '\n';     // O(1)，begin() 是最小值
        cout << "集合中最大值：" << *S.rbegin() << "\n\n";  // O(1)，rbegin() 是最大值
    }

    // 输出 map 中的最小和最大键
    if (!M.empty()) {
        cout << "映射中最小的键：" << M.begin()->first << '\n';     // O(1)
        cout << "映射中最大的键：" << M.rbegin()->first << '\n';    // O(1)
    }
}

int main() {
    // 禁用输入输出流同步，提高速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;  // T 测试用例数量：O(1)

    while (T--) {  // 最多执行 T 次
        cout << "=== 测试用例 ===\n";
        solve();  // 每次调用 solve(): O(n log n)
    }
}