#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k, p;
        cin >> n >> k >> p;
        if(k < 0) k *= -1;
        int tmp = (k + p - 1) / p;
        //特判-1
        if(tmp > n) {
            cout << "-1\n";
        }
        else {
            cout << (k + p - 1) / p << '\n';
        }
    } 
}