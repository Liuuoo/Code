#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ddown = 0;
        int uup = 0;
        while(n--) {
            char c;
            cin >> c;
            if(c == '_') ddown++;
            if(c == '-') uup++;
        }
        cout << uup/2 * (uup - (uup/2)) * ddown << '\n';
    }
}