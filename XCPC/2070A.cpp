#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int tmp = (n / 15) * 3;
    int las = (n % 15) >= 2 ? 2 : n % 15;
    cout << tmp + las + 1 << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}