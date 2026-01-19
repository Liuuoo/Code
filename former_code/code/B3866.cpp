#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    while (n != 495) {
        // 分解当前数字的各位
        int a = n / 10 / 10 % 10;
        int b = n / 10 % 10;
        int c = n % 10;

        // 排序三个数字，得到 x <= y <= z
        int x = a, y = b, z = c;

        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);

        // 构造最大值和最小值
        int max_num = z * 100 + y * 10 + x;
        int min_num = x * 100 + y * 10 + z;

        // 得到新的三位数
        n = max_num - min_num;
        count++;
    }

    cout << count << endl;

    return 0;
}