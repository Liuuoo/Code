#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    bool vis[123] = {false};
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[i] == a[j] + a[k] && vis[i] == false && j != k) {
                    ans++;
                    vis[i] = true;
                }
            }
        }
    }
    cout << ans;
}