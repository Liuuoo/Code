#include <bits/stdc++.h>
using namespace std;

int main() {
    int x0, y0;
    cin >> x0 >> y0;
    
    if (y0 % x0 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int k = y0 / x0;
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    int m = 0;
    int temp = k;
    for (int i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            m++;
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }
    if (temp > 1) {
        m++;
    }
    
    cout << (1 << m); // 使用位运算计算2的m次方
}