#include<bits/stdc++.h>
using namespace std;
const int N = 32;
int mid[N];
int fro[N];

struct Item{
    int l;
    int r;
};
Item tree[1234];

int dfs(int fl, int fr, int ml, int mr) {

    // cout << fl << " " << fr << " " << ml << " " << mr << '\n';

    if(fl == fr) return fro[fl];
    if(fl > fr) return 0;
    int midroot = ml;
    for(int i = ml; i <= mr; i++) {
        if(mid[i] == fro[fl]) {
            midroot = i;
            break;
        }
    }
    bool vis[1234] = {false};
    for(int i = ml; i <= midroot; i++) vis[mid[i]] = true;

    int frori = fr + 1;
    for(int i = fl; i <= fr; i++) {
        if(vis[fro[i]] == false) {
            frori = i;
            break;
        }
    }

    tree[fro[fl]].r = dfs(fl + 1, frori - 1, ml, midroot - 1);
    tree[fro[fl]].l = dfs(frori, fr, midroot + 1, mr);
    return fro[fl];
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> mid[i];
    for(int i = 1; i <= n; i++) cin >> fro[i];
    dfs(1, n, 1, n);
    queue<int> q;
    q.push(fro[1]);
    vector<int> ans;
    while(!q.empty()) {
        int tf = q.front();
        ans.push_back(tf);
        q.pop();
        if(tree[tf].l != 0) q.push(tree[tf].l);
        if(tree[tf].r != 0) q.push(tree[tf].r);
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i != ans.size() - 1 ? " " : "");
    }
}