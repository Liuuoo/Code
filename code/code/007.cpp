#include<bits/stdc++.h>
using namespace std;
map<string, int> dks;
map<string, int> dhs;
map<string, int> dsq;
map<string, bool> vis;

struct Node {
    int nums;
    int hs;
    int sq;
};

struct Item {
    string fid;
    string mid;
    vector<string> clids;
    int num;
    int sq;
};

struct node2 {
    string id;
    int nums;
    double hs;
    double sq;
};

bool cmp(node2 &i, node2 &j) {
    if(i.sq != j.sq) return i.sq > j.sq;
    else return i.id < j.id;
}

map<string, Item> arr;
map<string, string> pr;       
vector<node2>ans;

string findset(string s) {
    if(pr[s] != s) pr[s] = findset(pr[s]);
    return pr[s];
}

void merge(string s1, string s2) {
    string ns1 = findset(s1);
    string ns2 = findset(s2);
    if(ns1 > ns2) pr[ns1] = ns2;
    else pr[ns2] = ns1;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string _1, _2, _3;
        cin >> _1 >> _2 >> _3;
        pr[_1] = _1;
        vis[_1] = false;
        if(_2 != "-1") pr[_2] = _2, vis[_2] = false;
        if(_3 != "-1") pr[_3] = _3, vis[_3] = false;
        int k;  cin >> k;
        vector<string> cs;
        while(k--) {
            string s;
            cin >> s;
            pr[s] = s;
            vis[s] = false;
            cs.push_back(s);
        }
        int _4, _5;
        cin >> _4 >> _5;
        arr[_1] = {_2, _3, cs, _4, _5};
    }

    for(auto x: arr) {
        if(x.second.fid != "-1") merge(x.first, x.second.fid);
        if(x.second.mid != "-1") merge(x.first, x.second.mid);                          
        for(auto y: x.second.clids) {
            merge(x.first, y);
        }

    }

    map<string, Node> tans;

    for(auto x: arr) {
        int tmp = 0;
        if(vis[x.first] == false) {
            tmp++;
            vis[x.first] = true;
        }
        if(x.second.fid != "-1") {
            if(vis[x.second.fid] == false) {
                tmp++;
                vis[x.second.fid] = true;
            }
        }
        if(x.second.mid != "-1") {
            if(vis[x.second.mid] == false) {
                tmp++;
                vis[x.second.mid] = true;
            }
        }
        tans[findset(x.first)].sq += x.second.sq;
        tans[findset(x.first)].hs += x.second.num;
        for(auto y: x.second.clids) {
            if(!vis[y]) {
                tmp++;
                vis[y] = true;
            }
        }
        tans[findset(x.first)].nums += tmp;
    }

    for(auto x: tans) {
        if(findset(x.first) == x.first) {
            //cout << x.first << " " << x.second.nums << " " << x.second.hs << " " << x.second.sq << "\n";
            ans.push_back({x.first, x.second.nums, (x.second.hs *1.0 / x.second.nums), (x.second.sq * 1.0 / x.second.nums)});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << "\n";
    for(auto x: ans) {
        cout << fixed << setprecision(3);
        cout << x.id << " " << x.nums << " " << x.hs << " " << x.sq << "\n";
    }
}
