#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, string> dict;
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        dict[a] = b;
    }
    string s;
    cin >> s;
    string ans, tmp;
    for(char c: s) {
        if(islower(c)) tmp += c;
        else {
            if (!tmp.empty()) {
                if (dict.count(tmp)) {
                    ans += dict[tmp];
                } 
                else {
                    ans += "UNK";
                }
                tmp = "";
            }
            ans += c;
        }
    }
    // 处理最后一个单词
    if (!tmp.empty()) {
        if (dict.count(tmp)) {
            ans += dict[tmp];
        } else {
            ans += "UNK";
        }
    }
    cout << ans;
}