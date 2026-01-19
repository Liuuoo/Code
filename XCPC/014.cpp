#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
bool vis[MAXN];
int arr[MAXN];

int bsearch(int n, int rr) {
    int l = 0, r = rr;  // [0, n)
    while(l < r) {
        int m = (l + r) >> 1;
        if(arr[m] >= n) r = m;
        else l = m + 1;
    }                       //终止于 l = r
    return l;
}

int main() {
    std::cin.tie(nullptr); // 解绑定 cin 和 cout，避免自动刷新
    std::ios::sync_with_stdio(false); // 禁用与 C 的 I/O 同步
    int n, ans = 0; //ans表示轨道的个数
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        int inx = bsearch(x, ans);
        arr[inx] = x;
        if(inx == ans) ans++;
        
    }
    cout << ans;
}