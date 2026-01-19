#include<bits/stdc++.h>
using namespace std;
const int N = 5110;
bool box[N][N];
int n, m;
set<int> s;
int fa[N];

int findset(int nn) {
    if(fa[nn] == nn) return nn;
    return fa[nn] = findset(fa[nn]);
}

void merg(int a,int b) {
    int na = findset(a);
    int nb = findset(b);
    fa[na] = nb;
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i< n; i++) s.insert(i);
    while(m--) {
        int a, b;
        cin >> a >> b;
        box[a][b] = true;
        box[b][a] = true;
    }
    int k;  cin >> k;
    while(k--) {
        
        int cnt1 = 0, cnt2 = 0;
        int x;  cin >> x;
        for(int i = 0; i < n; i++) fa[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(box[i][j]) merg(i, j);
            }
        }
        for(int i = 0; i < n; i++) {
            if(s.find(i) != s.end()) {
                if(findset(i) == i) 
                cnt1++;
            }
        }
        s.erase(x);
        for(int i = 0; i < n; i++) {
            if(box[x][i]) {
                box[x][i] = false;
                box[i][x] = false;
            }
        }
        for(int i = 0; i < n; i++) fa[i] = i;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(box[i][j]) merg(i, j);
            }
        }
        for(int i = 0; i < n; i++) {
            if(s.find(i) != s.end()) {
                if(findset(i) == i) 
                cnt2++;
            }
        }
        /// cout << cnt1 << " " << cnt2 << "\n";
        if(cnt1 + 1 < cnt2) {
            cout << "Red Alert: ";
            cout << "City " << x << " is lost!\n";
        }
        else cout << "City " << x << " is lost.\n";
        if(s.empty()) {
            cout << "Game Over.";
            break;
        }
    }
}