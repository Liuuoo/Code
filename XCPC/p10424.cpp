#include<bits/stdc++.h>
using namespace std;

bool is_good(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    s = "$" + s;
    for(int i = 1; i < s.size(); i++) {
        int num = s[i] - '0';
        if(i % 2 == 0 && num % 2 != 0) return false;
        if(i % 2 != 0 && num % 2 == 0) return false;
    }
    return true;
}

int main() {
    int N;  cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++) if(is_good(i)) ans++;
    cout << ans;
}