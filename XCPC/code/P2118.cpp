#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, l;
    cin >> a >> b >> l;
    double val = a*1.0/b;
    double ans = 1e7;
    int aa = 0;
    int bb = 0;
    for(int i = 0; i <= l; i++) {
        for(int j = 0; j <= l; j++) {
            if(__gcd(i, j) == 1 && i*1.0/j >= val && i*1.0/j - val < ans) {
                ans = abs(i*1.0/j - val);
                aa = i;
                bb = j;
            }
        }
    }
    cout << aa << " " << bb;
}