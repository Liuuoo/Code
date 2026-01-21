#include<bits/stdc++.h>
using namespace std;
int a[1234];
bool isfro = true;
bool isSearchTree = true;

struct Item {
    int lc;
    int rc;
};
Item tree[1111];

int dfs(int l, int r) {
    if(l >= r || !isSearchTree) {
        return l;
    }
    int tmp = r + 1;
    for(int i = l + 1; i <= r; i++) {
        if(a[i] - a[l] >= 0 && isfro || a[i] - a[l] < 0 && !isfro) {
            tmp = i;
            break;
        }
    }
    
    for(int i = tmp; i <= r; i++) {
        if(a[i] - a[l] >= 0 && !isfro || a[i] - a[l] < 0 && isfro) {
            isSearchTree = false;
            break;
        }
    }
    tree[l].lc = dfs(l + 1, tmp - 1);
    tree[l].rc = dfs(tmp, r);
    return l;
}
vector<int> ans;
void dis(int root) {
   // cout << root << "\n";
    if(root == -1) return;
    dis(tree[root].lc);
    dis(tree[root].rc);
    ans.push_back(a[root]);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[1] - a[0] >= 0) isfro = false; 
    dfs(0, n - 1);
    if(isSearchTree) {
        cout << "YES\n";
        for(int i = 1; i < n; i++) if(tree[i].lc == 0 && tree[i].rc == 0) {
            tree[i].lc = -1;
            tree[i].rc = -1;
        }
        dis(0);
        for(int i = 0; i < ans.size(); i++) {
            if(i < ans.size() - 1) cout << ans[i] << " ";
            else cout << ans[i];
        }
    }
    else cout << "NO";
}