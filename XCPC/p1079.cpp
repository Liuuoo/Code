#include <bits/stdc++.h>
using namespace std;

int main() {
    string k, s;
    cin >> k >> s;
    
    vector<int> tmp;

    for(char x: k) tmp.push_back(toupper(x) - 'A');
    int k_len = tmp.size();
    
    string ans = "";
    for(int i = 0; i < s.size(); ++i) {
        char c = s[i];
        int c_num = toupper(c) - 'A'; // 统一成大写
        int k = tmp[i % k_len]; 
        int m_num = (c_num - k + 26) % 26; // 易错：+26
        ans += isupper(c) ? 'A' + m_num : 'a' + m_num; 
    }
    
    cout << ans;
}