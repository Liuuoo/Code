#include<bits/stdc++.h>
using namespace std;
int ba[45];
int mid[45];

struct Item{
    int lc;
    int rc;
};
Item tree[45];
vector<int> ans;
int dfs(int bal, int bar, int ml, int mr) {
    //cout << bal << " " << bar << " " << ml << " " << mr << '\n'; 
    if(ml == mr && bal == bar) {
        // cout << ba[bal]; //叶节点
        return ba[bal];
    }
    if(ml > bar && ml > mr) return -1; //空节点
    int mtmp;
    for(int i = mr; i >= ml; i--) {
        if(mid[i] == ba[bar]) {
            mtmp = i; //根节点
            break;
        }
    }
    bool inr[450] = {false};
    int batmp = 0;
    for(int i = mtmp + 1; i <= mr; i++) inr[mid[i]] = true; //右子树节点
    for(int i = bar - 1; i >= bal; i--) { //从后根遍历的后往前
        if(!inr[ba[i]]) {
            batmp = i; //最后一个左子树节点
            //cout << batmp; 
            break;
        }
    }
    tree[ba[bar]].lc = dfs(bal, batmp, ml, mtmp - 1);
    tree[ba[bar]].rc = dfs(batmp + 1, bar - 1, mtmp + 1, mr);
    return ba[bar];
}

void dis(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int ro = q.front();
        ans.push_back(ro);
        q.pop();
        int l = tree[ro].lc;
        int r = tree[ro].rc;
        if(l != -1) q.push(l);
        if(r != -1) q.push(r);
    }
}

int main() {
    int n;  cin >> n;
    memset(tree, -1, sizeof(tree));
    for(int i = 1; i <= n; i++) cin >> ba[i];
    for(int i = 1; i <= n; i++) cin >> mid[i];
    dfs(1, n, 1, n);
    // for(int i = 1; i <= n; i++) cout << tree[mid[i]].lc << " " << tree[mid[i]].rc << "\n";
    dis(ba[n]);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i != ans.size() - 1 ? " " : "");
    }
}