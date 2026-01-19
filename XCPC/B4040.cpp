#include<bits/stdc++.h>
using namespace std;
const int N = 123;
string s[N];
int n, m;

bool jud(int x, int y) {
    if(x + 4 >= n || y + 4 >= m) return false;
    for(int i = x; i < x + 4; i++) {
        for(int j = y; j < y + 4; j++) {
            if(i == x || i == x + 3) {
                if(s[i][j] == '1') return false;
            }
            else {
                if(j == y || j == y + 3) {
                    if(s[i][j] == '1') return false;
                }
                else {
                    if(s[i][j] == '0') return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(jud(i, j)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}