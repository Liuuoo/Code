#include<bits/stdc++.h>
using namespace std;
const int N = 123;
int fir[N];
bool arm[N][N];

int findfriend(int n) {
    if(fir[n] != n) fir[n] = findfriend(fir[n]);
    return fir[n];
}

void merge_fri(int a, int b) {
    int na = findfriend(a);
    int nb = findfriend(b);
    fir[na] = nb;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) fir[i] = i;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 1) merge_fri(a, b);
        else {
            arm[a][b] = true;
            arm[b][a] = true;
        }
    }
    while(k--) {
        int a, b;
        cin >> a >> b;
        if(findfriend(a) == findfriend(b) && !arm[a][b]) cout << "No problem\n";
        if(findfriend(a) != findfriend(b) && !arm[a][b]) cout << "OK\n";
        if(findfriend(a) == findfriend(b) && arm[a][b]) cout << "OK but...\n";
        if(findfriend(a) != findfriend(b) && arm[a][b]) cout << "No way\n";
    }
} 