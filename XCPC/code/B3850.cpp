#include<bits/stdc++.h>
using namespace std;

int calc(string &s) {
    reverse(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans = ans + (s[i] - '0');
    }
    s = to_string(ans);
    return ans;
}

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s = "$" + s;

    for(int i = 1; i < s.size(); i++) {
        int c = s[i] - '0';
        c *= 7;
        if(i % 2 != 0) {
            if(c <= 9) {
                c += '0';
                s[i] = c;
            }
            else {
                string tmp = to_string(c);
                int sum = 10;
                while(sum > 9) {
                    sum = calc(tmp);
                }
                s[i] = sum + '0';
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < s.size(); i++) {
        ans = ans + (s[i] - '0');
    }
    if(ans % 8 == 0) cout << "T\n";
    else cout << "F\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}