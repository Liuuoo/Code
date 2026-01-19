#include<bits/stdc++.h>
using namespace std;    
vector<int> vec;

int k;

bool jud(int x, int n) {
    for(int i = 0; i < n; i++) {
        if(i + x - 1 < n && vec[i + x - 1] - vec[i] <= k) return true;
    } 

    return false;
}

int bs(int n) {
    int l = 0, r = n;
    while(l < r) {
        //cout << l << " " << r << '\n';
        int m = (l + r + 1) >> 1;
        if(jud(m, n)) l = m;
        else r = m - 1;
    }
    return r;
}

int main() {
    int n;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int l1 = bs(n);
    for(int i = 0 ; i < n; i++) {
        if(vec[i + l1] - vec[i] <= k) {
            int j = i;
            for(int j = i; j <= i + l1; j++) {
                vec[i] = INT_MAX;
            }
        }
    }
    sort(vec.begin(), vec.end());
    int l2 = bs(n - l1);
    cout << l1 + l2;
}