#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> s[n + 1];
    for(int i = 1; i <= n; i++) {
        int m;  cin >> m;
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            s[i].insert(x);
        }
    }
    
    int k;  cin >> k;
    while(k--) {
        int a, b;
        cin >> a >> b; 
        int cnt = 0;
        for(auto x: s[a]) {
            if(s[b].find(x) != s[b].end()) {
                cnt++;
            }
        }
        double ans = cnt*1.0 / (s[a].size() + s[b].size() - cnt)*1.0;
       // cout << cnt << " " << s[a].size() << " " << s[b].size() << "\n";
        printf("%.2llf\n", ans);
    }
}