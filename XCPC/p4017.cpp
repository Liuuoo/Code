#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=80112002;
const int N=5e3+10;
vector<int> ot[N];
vector<int> in[N];
int dp[N]; // 到生产者的路径数量
int dfs(int u)
{
    // cout<<u<<'\n';
    if(dp[u]) return dp[u];
    if(ot[u].size()==0)
    {
        dp[u]=1;
        return dp[u];
    }
    int res=0;
    for(auto x:ot[u])
    {
        res+=dfs(x);
        res%=mod;
    }
    // res%=mod;
    return dp[u]=res%mod;
}
signed main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        ot[u].push_back(v);
        in[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(in[i].size()==0)
        {
            ans+=dfs(i);
            ans%=mod;
        }
    }
    cout<<ans;
}