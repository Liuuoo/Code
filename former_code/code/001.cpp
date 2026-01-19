#include<bits/stdc++.h>
using namespace std;
int g[555][555];
bool vis[555];
int len[555] = {0};
bool dvis[555];
int ans = 0;
int MAXN;
int maxp = 0;
queue<int> q; 
int num[555];
vector<int> avec[555];
int disp[555];
int ansp[555];
int si;

struct Item {
    int a;
    int dis;
};

struct cmp {
    bool operator()(Item &i, Item &j) {
        return i.dis > j.dis;
    }
};

void dfs(int n, int d, int step, int m, int gp, int leve) {
    gp += num[n];
    avec[ans].push_back(n);
    // cout << ans << "\n";
    if(step >= m) {
        if(n == d && step == m) {
            if(maxp < gp) {
                maxp = gp;
                si = leve;
                for(int i = 0 ; i < si; i++) ansp[i] = disp[i];
            }
            ans++;
        }
        return;
    }
    for(int i = 0; i < MAXN; i++) {
        if(!dvis[i] && g[n][i] != -1) {
            dvis[i] = true;
            disp[leve] = i;
            dfs(i, d, step + g[n][i], m, gp, leve + 1);
            dvis[i] = false;
        }
    }
}

int main() {
    memset(g, -1, sizeof(g));
    while (!q.empty()) q.pop();

    for(int i = 0; i < 555; i++) len[i] = INT_MAX;
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    MAXN = n;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    maxp = num[s];
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    vis[s] = true;
    len[s] = 0;
    int minl = 0;
    int fr;
    q.push(s);
    while(!q.empty()) {
        fr = q.front();
        vis[fr] = true;
        minl = len[fr];
        q.pop();
        if(fr == d) break;
        int tmp;
        priority_queue<Item, vector<Item>, cmp> pq;
        for(int i = n - 1; i >= 0; i--) {
            if(g[fr][i] != -1 && !vis[i]) {
                len[i] = min(len[i], minl + g[fr][i]);
                pq.push({i, len[i]});
                // cout << len[i] << " ";
            }
        }
        q.push(pq.top().a);
    }
    dfs(s, d, 0, len[d], 0, 0);
    cout << ans << " " << maxp << "\n";
    cout << s;
    for(int i = 0; i < si; i++) cout << " " << ansp[i];
}
