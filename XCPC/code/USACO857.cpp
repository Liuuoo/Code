#include<bits/stdc++.h>
using namespace std;

vector<int> veca;
vector<int> vecb;
bool visindxa[12345] = {false};
bool visindxb[12345] = {false};
set<int> ans;

void dfs(vector<int> &veca, vector<int> &vecb, int n, int v) {
    if(n > 5) {
        if(ans.find(v) == ans.end()) {
            ans.insert(v);
            //cout << v << '\n';
        }
        return;
    }
    if(n % 2 != 0) {
        for(int i = 0; i < veca.size(); i++) {
            if(!visindxa[i]) {
                vecb.push_back(veca[i]);
                visindxa[i] = true;
                dfs(veca, vecb, n + 1, v - veca[i]);
                visindxa[i] = false;
                vecb.pop_back();
            }
        }
    }
    else {
        for(int i = 0; i < vecb.size(); i++) {
            if(!visindxb[i]) {
                veca.push_back(vecb[i]);
                visindxb[i] = true;
                dfs(veca, vecb, n + 1, v + vecb[i]);
                visindxb[i] = false;
                veca.pop_back();
            }
        }
    }
}

int main() {
    ans.insert(0);
    for(int i = 0 ; i < 10; i++) {
        int x;  cin >> x;
        veca.push_back(x);
    }
    for(int i = 0 ; i <10; i++) {
        int x;  cin >> x;
        vecb.push_back(x);
    }
    dfs(veca, vecb, 2, 0);
    cout << ans.size();
}