#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int a[N], b[N];
int n, k;

bool jud(int x) {
	int num = 0;
	for(int i = 0; i < n; i++) {
		num += (a[i]/x * b[i]/x);
	}
	if(num >= k) return true;
	else return false;
}

signed main() {
	cin >> n >> k;
	int l = 1, r = 1e5 + 10;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i]; 
	}
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(jud(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
}
