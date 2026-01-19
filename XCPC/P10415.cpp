#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int w, h;
	cin >> w >> h;
	if(w > h) swap(w, h);
	int max_v = max(w, h);
	int ans = 0;
	for(int i = 2; i <= sqrt(h); i++) {
		if(!(w % i) && !(h % i)) {
			ans = i;
			break;
		}
	}
	if(ans == 0) {
		if(!(h % w)) cout << 2; 
		else cout << 0;
	}
	else cout << w/ans * h/ans;
}
