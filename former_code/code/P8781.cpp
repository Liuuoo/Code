#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int ans[N];
int main() {
	int n;  cin >> n;
	int i = 0;
	int tmp = 7;
	while(tmp--) {
		while(1) {
			// cout << i << " ";
			for(int j = 0; j < n; j++) {
				a[j]++;
				ans[j] = max(ans[j], a[j]);
			}
			a[i] = 0;
			if(tmp % 2) i++;
			else i--;
			if(i == n) {
				i = n - 2;
				break;
			}
			if(i == -1) {
				i = 1;
				break;
			}
		}
	}
	// cout << '\n';
	for(int i = 0; i < n; i++) cout << ans[i] << "\n";
} 
