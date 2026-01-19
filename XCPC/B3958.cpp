#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.size() < s2.size()) swap(s1, s2);
        if(s1.size() == s2.size()) {
            int cnt = 0;
            for(int i = 0; i < s1.size(); i++) {
                if(s1[i] != s2[i]) cnt++;
            }
            if(cnt <= 1) cout << "similar\n";
            else cout << "not similar\n";
        }
        else if(s1.size() - s2.size() > 1) {
            cout << "not similar\n";
        }
        else {
            
            int i = 0, j = 0;
            int cnt = 0;
            while(1) {
                if(s1[i] != s2[j]) {
                    cnt++;
                    i++;
                }
                else {
                    i++;
                    j++;
                }
                if(i == s1.size() || j == s2.size()) break;
            }
            if(cnt <= 1) cout << "similar\n";
            else cout << "not similar\n";
        }

    }
    

}