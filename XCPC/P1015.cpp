#include<bits/stdc++.h>
using namespace std;
int n; string m;

vector<char> m_add(vector<char> s2) {
    // 无需考虑001
    vector<char> s1 = s2;
    reverse(s1.begin(), s1.end());
    vector<char> ans;
    bool is_add = false;
    for(int i = 0; i < s1.size(); i++) {
        // cout << (int)s1[i] << " ";
        if(isalpha(s1[i])) s1[i] -= 'A' - 10;
        else s1[i] -= '0';
        if(isalpha(s2[i])) s2[i] -= 'A' - 10;
        else s2[i] -= '0';
        // cout << (int)s1[i] << '\n';
        char tmp;
        tmp = s1[i] + s2[i] + is_add;
        if(tmp >= n) is_add = 1;
        else is_add = 0;
        tmp = tmp%n;
        if(tmp < 10) tmp += '0';
        else tmp = tmp - 10 + 'A';
        ans.push_back(tmp);
    }
    if(is_add) ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<char> s;
    cin >> n >> m;
    for(auto x: m) s.push_back(x);
    vector<char> tmp = s;
    reverse(s.begin(), s.end());
    int t = 31;
    int cnt = 0;
    while(t--) {
        //cout << "\n";
        cnt++;
        vector<char> ans = m_add(tmp);
        //for(auto x:ans) cout << x;
        tmp = ans;
        reverse(ans.begin(), ans.end());
        if(tmp == ans) break;
    }
    if(cnt == 31) cout << "Impossible!";
    else cout << "STEP=" << cnt;
}