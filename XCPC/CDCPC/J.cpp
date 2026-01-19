#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int id;
    int coin;
    bool operator<(Node a)
    {
        if(a.coin!=coin) return coin>a.coin;
        else return id<a.id;
    }
};

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    int b_m=-1;
    vector<int>las_coin(n+1,m);

    map<int,int> st; // st-学生得分
    map<int,set<int>> comp; // 学生完成的题
    map<int,set<int>> give_up;
    // map<int,bool>g;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            // g.clear();
            int x;
            cin>>x;
            b_m=x;
        }
        else if(t==2)
        {
            int id,x;
            cin>>id>>x;
            if(x!=b_m) continue;

            if(!comp[id].count(x)&&!give_up[id].count(x))
            {
                comp[id].insert(x);
                st[id]+=las_coin[x];
                las_coin[x]--; 
            }
        }
        else 
        {
            int id,x;
            cin>>id>>x;
            // if(g[id]==true) continue;
            if(x!=b_m) continue;
            give_up[id].insert(x);
            // g[id]=true;
        }
    }   
    vector<Node>ans;
    for(int i=1;i<=m;i++)
    {
        ans.push_back({i,st[i]});
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x.id<<" "<<x.coin<<'\n';
    }
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}