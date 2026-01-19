#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;  cin >> n;
    int64_t a[2*n + 1];
    for(int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a, a + 2*n, greater<int>());
    int64_t tmp1 = 0, tmp2 = 0;
    for(int i = 0; i < 2*n; i++) {
        if(i % 2 == 0) tmp1 += a[i];
        else tmp2 += a[i];
    }
    cout << tmp1 - tmp2 << " ";
    for(int i = 0; i < 2*n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}