#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int min_v = INT_MIN;
	int max_v = INT_MAX; 
	while(n--) {
		double a, b;
		cin >> a >> b;
		int ma = int(a/(b + 1.0) + 1);
		int mi = int(a/b);
		min_v = max(min_v, ma);
		max_v = min(max_v, mi);
		// cout << ma << " " << mi << '\n';
	}
	cout << min_v << " " << max_v;
} 
