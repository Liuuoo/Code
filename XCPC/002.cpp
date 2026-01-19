#include<bits/stdc++.h>
using namespace std;
bool vis[1111111];
struct Item{
    int data;
    int p;
};
Item lis[1111111];

vector<Item> vec[2];

int main() {
    int head, n;
    cin >> head >> n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        lis[a].data = b;
        lis[a].p = c;
    }
    int t = head;
    while(t != -1) {
        // cout << lis[t].data << " ";
        if(!vis[abs(lis[t].data)]) {
            vis[abs(lis[t].data)] = true;
            vec[0].push_back({lis[t].data, t});
        }
        else vec[1].push_back({lis[t].data, t});
        t = lis[t].p;
    }
    for(int i = 0; i < 2; i++) {
        int MAXS = vec[i].size();
        for(int j = 0; j < MAXS - 1; j++) {
            printf("%05d %d %05d\n", vec[i][j].p, vec[i][j].data, vec[i][j + 1].p);
        }
        if(MAXS >= 1) {
            if(MAXS > 1) printf("%05d %d", vec[i][MAXS - 1].p,vec[i][MAXS - 1].data);
            if(MAXS == 1) printf("%05d %d ", vec[i][MAXS - 1].p,vec[i][MAXS - 1].data);
            cout << " -1" << "\n";
        }
    }
}