#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int>W;
map<int,vector<int>> g;
int maxLen=0;
map<int,bool> vis;

void dfs(int x,int len)
{
    vis[x]=true;
    maxLen=max(maxLen,len);
    for(auto u:g[x])
    {
        if(!vis[u])
        {
            dfs(u,len+W[{x,u}]);
        }
    }
}

signed main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
        W[{u,v}]=w;
        W[{v,u}]=w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    sum*=2;
    cout<<sum-maxLen;
}