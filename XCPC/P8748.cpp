#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;  cin >> n;
	n /= 1000;
	n = n % (60*60*24);
	printf("%02d", n / (60*60));
	n = n % (60*60);
	printf(":%02d", n / 60);
	n %= 60;
	printf(":%02d", n);
}
