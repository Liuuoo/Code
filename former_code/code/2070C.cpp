#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int loss[N];    
int n, k;
string s;

bool jud(int x) {
    vector<char> vec;
    for(int i = 0; i < n; i++) {
        if(loss[i] >= x) vec.push_back(s[i]);
    }

    int beg = 0;
    int ed = vec.size() - 1;
    // cout << vec.size() << "\n";
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == 'R') beg++;
        else break;
    }
    for(int i = ed; i >= beg; i--) {
        if(vec[i] == 'R') ed--;
        else break;
    }
    // cout << x << " " << beg << " " << ed << "\n";
    if(ed == beg) return true;

    int cnt = 0;
    for(int i = beg + 1; i <= ed; i++) {
        if(vec[i - 1] == 'B' && vec[i] == 'R') cnt++;
    }
    // cout << x << " " << cnt << "\n";
    if(cnt + 1 <= k) return true;
    else return false;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    int tmp[n + 1];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        loss[i] = x;
        tmp[i] = x;
    }
    sort(tmp, tmp + n);
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(jud(tmp[mid])) r = mid - 1;
        else l = mid + 1;
    }
    if(r == -1) cout << "0\n";
    else cout << tmp[r] << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}