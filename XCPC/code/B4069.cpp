#include<bits/stdc++.h>
using namespace std;

bool jud(string s) {
    char c = 'a';
    for(int j = 0; j < s.size(); j++) {
        if(c > s[j]) return false;
        c = s[j];
    }
    return true;
}


void solve() {
    int n;
    cin >> n;
    int sum = 0;
    string s[n + 1];
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s[sum++] = tmp;
    }
    sort(s, s + sum);
    string ans;
    for(int i = 0; i < sum; i++) {
        ans += s[i];
    }
    if(jud(ans)) cout << "1\n";
    else cout << "0\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}
