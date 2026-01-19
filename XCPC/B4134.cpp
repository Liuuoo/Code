#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;  cin >> n;
//	for(int i = 2; i <= n; i++) {
//		int cnt = 0;
//		for(int j = 1; j <= i; j++) {
//			if(i % j == 0) cnt++;
//		} 
//		if(cnt % 2) {
//			cout << i << '\n';
//			for(int j = 1; j <= i; j++) {
//				if(i % j == 0) cout << j << " ";
//			} 
//			cout << '\n';
//		}
//	} 	
	long long ans = 0;
	for(int i = 2; i <= sqrt(n); i++) {
		ans += i * i;
	}
	cout << ans + 1;
} 




