#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    // for(int j = 1; j < 1236123; j++) {
        cin >> n;
        int t = 0;
        // cout << n << " ";
        while(n) {
            string s = to_string(n);
            int tmp = 0;
            for(int i = 0; i < s.size(); i++) {
                tmp = tmp + s[i] - '0';
            }
            n = n - tmp;
            t++;
        }
        cout << t << '\n';
    // }
}