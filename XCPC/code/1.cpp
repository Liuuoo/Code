#include<bits/stdc++.h>
using namespace std;
int box[13][13];
int x, y;
int xx[] = {0 , 1, 0, -1};
int yy[] = {1, 0, -1, 0};
int n;

void dfs(pair<int, int> dis, pair<int, int> tar, vector<int> &vec) {
    if(dis == tar) {
        for(auto x: vec) cout << x;
        return;
    }
    
}

pair<int, int> bfs(int i, int j) {
    bool vis[12][12] = {false};
    vis[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()) {
        int ox, oy;
        ox = q.front().first;
        oy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = ox + xx[i];
            int ny = ox + yy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && !vis[nx][ny]) {
                if(box[nx][ny] == '1') {
                    x = nx, y = ny;
                    return {x, y};
                }
                else q.push({nx, ny});
            }
        }
    }
    return {-1, -1};
}


int main() {
    cin >> n;
    pair<int, int> ini;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        s = '$' + s;
        for(int j = 1; j <= n; j++) {
            box[i][j] = s[j] - '0';
            if(s[j] == '2') ini = {i, j};
        }
    }
    while(1) {
        pair<int, int> food = bfs(ini.first, ini.second);
        if(food.first == -1 && food.second == -1) break;
        else {
            vector<int> vec(12345);
            dfs(ini, food, vec);
            ini = food;
        }
    }
}