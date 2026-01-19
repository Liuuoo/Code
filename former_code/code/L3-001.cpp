#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(m + 1);
    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            vector<int> tmp;
            if(dp[j - a[i]].empty() || j - a[i] == 0) {
                tmp = dp[j - a[i]];
                tmp.push_back(a[i]);
            }
            dp[j] = min(dp[j], tmp);
        }
    }
    if(dp[m].empty()) cout << "No Solution";
    else for(auto x: dp[m]) cout << x << " ";
}