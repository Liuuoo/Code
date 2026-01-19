#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
int vis[12][12];
int xx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int yy[] = {-1, 1, 1, -1, 1, -1, 0, 0};

void dfs(vector<vector<int>>& box, int n, int m, int sum, int level) {
    ans = max(ans, sum);
    int ii = -1, jj = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i >= 1 && j >= 1 && i <= n && j <= m && !vis[i][j]) {
                
                for(int k = 0; k < 8; k++) {
                    int ni = i + xx[k];
                    int nj = j + yy[k];
                    if(ni < 1 || nj < 1 || ni > n || nj > m) continue;
                    vis[i + xx[k]][j + yy[k]]++;
                }
                vis[i][j]++;
                dfs(box, n, m, sum + box[i][j], level + 1); 
                
                vis[i][j]--;
                for(int k = 0; k < 8; k++) {
                    int ni = i + xx[k];
                    int nj = j + yy[k];
                    if(ni < 1 || nj < 1 || ni > n || nj > m) continue;
                    vis[i + xx[k]][j + yy[k]]--;
                }
            }
        }
    }
}
                
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> box(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> box[i][j];
            vis[i][j] = 0;
        }
    }
    ans = 0;
    dfs(box, n, m, 0, 0);
    cout << ans << "\n";
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}