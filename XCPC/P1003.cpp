#include<bits/stdc++.h>
using namespace std;

struct carpet {
    int a, b, g, k;
};


int main() {
    int n;  cin >> n;
    carpet a[n + 1];
    for(int i = 0; i < n; i++) {
        int aa, b, g, k;
        cin >> aa >> b >> g >> k;
        a[i] = {aa, b, g, k};
    }
    int x, y;
    cin >> x >> y;
    for(int i = n - 1; i >= 0; i--) {
        int nx = a[i].a;
        int ny = a[i].b;
        int x_len = a[i].g;
        int y_len = a[i].k;
        if(x >= nx && x <= nx + x_len && y >= ny && y <= ny + y_len) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}