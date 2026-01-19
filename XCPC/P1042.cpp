#include<bits/stdc++.h>
using namespace std;
string s = "$";  

void solve(int n) {
    int a = 0, b = 0;
    int delt = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'E') {
             cout << a << ":" << b << '\n';
            break;
        }
        s[i] == 'W' ? a++ : b++;
        if(a >= n || b >= n) {
            delt = abs(a - b);
            if(delt >= 2) {
                cout << a << ":" << b << '\n';
                a = 0, b = 0;
            }
        }
    }
}

int main() {
    while(1) {
        string ss;
        cin >> ss;
        s += ss;
        if(ss.find('E') != -1) break;
    }
    solve(11);
    cout << "\n";
    solve(21);
}