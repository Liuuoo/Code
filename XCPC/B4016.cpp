#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g [N];
int maxlen=0;
int dp[N]; // dp_u表示u为根，最远到的距离
bool vis[N];

void dfs(int u)
{
    vis[u]=true;
    for(auto x:g[u])
    {
        if(vis[x]) continue;
        dfs(x);
        maxlen=max(maxlen,dp[u]+dp[x]+1);
        dp[u]=max(dp[u],dp[x]+1);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout<<maxlen;
}