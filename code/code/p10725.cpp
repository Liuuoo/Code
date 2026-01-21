#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>colo(N);
vector<int>g[N];
bool vis[N];
// bool vis2[N];
int dp[N][2]; // dp_u_0以节点u为根节点的最远的为0子节点的距离

int maxlen=0; 

int max(int x,int y,int z)
{
    return max(max(x,y),z);
}

void dfs(int u) 
{
    vis[u]=true;
    for(auto v:g[u])
    {
        if(vis[v]) continue;
        dfs(v);
        
        maxlen=max(maxlen,dp[u][0]+dp[v][1]+1,dp[u][1]+dp[v][0]+1);

        dp[u][0]=max(dp[u][0],dp[v][0]+1);
        dp[u][1]=max(dp[u][1],dp[v][1]+1);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {   
        dp[i][0]=dp[i][1]=-N*2;
        cin>>colo[i];
        dp[i][colo[i]]=0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<dp[i][0]<<" ";
    // }

    cout<<maxlen;
}