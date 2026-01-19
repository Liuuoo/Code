#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dp(n + 1, -1);
    
    function<int(int)> dfs = [&](int i) -> int {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        // 不选a[i]
        int res = dfs(i + 1);
        
        // 选a[i]作为某个block的元素
        int val = a[i];
        if(val > 0 && val <= n) {
            // 尝试以a[i]开始收集block_size个block_size
            int cnt = 0;
            int j = i;
            while(j < n && cnt < val) {
                if(a[j] == val) {
                    cnt++;
                }
                j++;
            }
            
            if(cnt == val) {
                // 可以形成一个完整的block
                res = max(res, val + dfs(j));
            }
        }
        
        return dp[i] = res;
    };
    
    cout << dfs(0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}