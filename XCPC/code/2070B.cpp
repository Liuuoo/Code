#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x, t;
    cin >> n >> x >> t;
    string s;
    cin >> s;
    int cnt = 0;
    bool getZero = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'L') x--, cnt++;
        else x++, cnt++;
        if(x == 0) {
            getZero = true;
            break;
        }
    }
    if(!getZero) cout << "0\n";
    else {
        int newX = 0;
        int newCnt = 0;
        bool newFlag = false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L') newX--, newCnt++;
            else newX++, newCnt++;
            if(newX == 0) {
                newFlag = true;
                break;
            }
        }
        if(!newFlag) cout << "1\n";
        else {
            cout << (t - cnt) / newCnt + 1 << '\n';
        }
    }
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}