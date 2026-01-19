#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int a[m + 1];
        set<int> b;
        for(int i = 0; i < m; i++) cin >> a[i];
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            b.insert(x);
        }
        if(k == n) {
            for(int i = 0; i < m; i++) cout << "1"; //a,b严格递增
        } 
        else if(k == n - 1) {
            for(int i = 0; i < m; i++) {
                if(b.find(a[i]) == b.end()) cout << "1";
                else cout << "0";
            }
        }
        else {
            for(int i = 0; i < m; i++) cout << "0"; //缺失太多
        }  
        cout << "\n";
    }
}