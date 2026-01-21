#include<bits/stdc++.h>
using namespace std;

map<string, bool> sexmap; //男-true
map<string, vector<string>> g;

void dfs1(string s, map<string, bool> &m, int n, map<string, bool> &vis) {
    if(n > 5 || s == "-1") return;
    for(auto x: g[s]) {
        if(!vis[x] && x != "-1") {
            vis[x] = true;
            // cout << x << "\n";
            m[x] = true;
            dfs1(x, m, n + 1, vis);
            vis[x] = false;
        }
    }
}
void dfs2(string s, map<string, bool> m, int n, map<string, bool> &vis, bool &jud) {
    if(n > 5 || s == "-1") return;
    //cout << s << " " << m[s] << "\n";
    if(m[s]) {
        jud = false;
        return;
    }
    for(auto x: g[s]) {
        if(!vis[x] && x != "-1") {
            //cout << x << "\n";
            vis[x] = true;
            dfs2(x, m, n + 1, vis, jud);
            vis[x] = false;
        }
    }
}

bool findper(string s1, string s2) {
    map<string, bool> vis;
    map<string, bool> tmpvis1;
    map<string, bool> tmpvis2;
    bool jud = true;

    dfs1(s1, vis, 1, tmpvis1);
    // for(auto x: vis) cout << x.first << " ";
    dfs2(s2, vis, 1, tmpvis2, jud);
    return jud;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s1, s2, s3;
        char sex;
        cin >> s1 >> sex >> s2 >> s3;
        sexmap[s1] = (sex == 'M');
        sexmap[s2] = true;
        sexmap[s3] = false;
        g[s1].push_back(s2);
        g[s1].push_back(s3);
    }
    int m;  cin >> m;
    while(m--) {
        string s1, s2;
        cin >> s1 >> s2;
        if(sexmap[s1] == sexmap[s2]) cout << "Never Mind\n";
        else if(findper(s1, s2) && s1 != s2) cout << "Yes\n";
        else cout << "No\n";
    }
}