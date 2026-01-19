#include<bits/stdc++.h>
using namespace std;
int main() { 
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int pre_sum[n + 1];
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    pre_sum[0] = 0;
    for(int i = 1; i <= n; i++) pre_sum[i] = pre_sum[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= i; j--) {
            if(a[j] - a[i] <= k) ans = max(ans, pre_sum[j] - pre_sum[i - 1]);
        }
    }
    cout << ans;
}