#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int tmp = (n - (m + 1)*k) / (m + 1);
    // cout << tmp << ' ';
    int t = 0;
    if(tmp >= 0) k = k + tmp;
    // cout << k << '\n';

    while(1) {
        if(t == n) break;
        cout << t % k << " ";
        t++;
    }

    
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}