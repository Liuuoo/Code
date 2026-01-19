#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    char xToY[26] = {0}; 
    char yToX[26] = {0}; 

    for (int i = 0; i < s1.size(); ++i) {
        char y = s1[i];
        char x = s2[i]; 

        if (xToY[x - 'A'] != 0 && xToY[x - 'A'] != y) { // X到Y已有，但又有了
            cout << "Failed" << '\n';
            return 0;
        }
        else xToY[x - 'A'] = y;

        if (yToX[y - 'A'] != 0 && yToX[y - 'A'] != x) { // Y已有但又有了（不同的字母对应不同的密字）
            cout << "Failed" << '\n';
            return 0;
        }
        else yToX[y - 'A'] = x;

    }

    for (int i = 0; i < 26; ++i) {
        if (xToY[i] == 0) {
            cout << "Failed" << '\n';
            return 0;
        }
    }

    string ans;
    for (char c : s3) {
        ans += yToX[c - 'A'];
        
    }
    cout << ans << '\n';
}

 