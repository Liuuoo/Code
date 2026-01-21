#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        s = '$' + s;
        cin >> s;
        int t = -1;
        int zero_cnt = 0;
        for(int i = 1; i < s.size(); i++) {
            while(s[i] == '0') {
                if(t == -1) t = i;
                zero_cnt++;
                i++;
            }
            if(t != -1) break; 
        }
        if(zero_cnt == 0) {
            cout << "1 " << s.size() << " 1 1\n";
        }
        else {
            if(t - zero_cnt > 0) {
                cout << "1 " << s.size() << " " << t-zero_cnt + 1 << " " << s.size() - zero_cnt << "\n";
            }
            else {
                cout << "1 " << s.size() << " " << "1 " << s.size() - t << "\n";
            }
        }
    }
}