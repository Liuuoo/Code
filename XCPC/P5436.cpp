#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        long long n;
        cin >> n;
        if(n == 1) cout << "1\n";
        else cout << n * (n - 1) << "\n";
    }
}