#include <bits/stdc++.h>
using namespace std;
const int N = 123;
bool vis[N][N];
int box[N][N];


int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int d = 0;
    int i = 0, j = 0;
    while(cnt < n*n) {
        box[i][j] = cnt++;
        if(d % 4 == 0) j++;
        else if(d % 4 == 1) i++;
        else if(d % 4 == 2) j--;
        else i--;
        if(vis[i][j] == true) d++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << '\n';
    }
}
