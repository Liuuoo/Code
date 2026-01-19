#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > sum/n) a[i + 1] += a[i] - sum/n, ans++;
        else if(a[i] < sum/n) a[i + 1] -= abs(a[i] - sum/n), ans++;
    }
    cout << ans;
}