#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int t;  cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        sort(a + l, a + r + 1);
        // for(int i = 1; i <= n; i++) cout << a[i] << " ";
        // cout << '\n';
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
}