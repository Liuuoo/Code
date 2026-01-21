#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
int n;
int per_sum[N];
signed main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
//	int ans = 0;
//	for(int i = 0; i < n - 1; i++) {
//		for(int j = i + 1; j < n; j++) {
//			ans += a[i] * a[j];
//		}
//	}
//	cout << ans;
	per_sum[0] = a[0];
	int ans = 0;
	for(int i = 1; i < n; i++) {
		ans += a[i] * per_sum[i - 1];
		per_sum[i] = per_sum[i - 1] + a[i];
	}
	cout << ans;
	
}
