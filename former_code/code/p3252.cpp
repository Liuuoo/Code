#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s;
int dp[N]; // dpu表示从根节点到u的路径和
struct Node
{
    int v;
    vector<int> son;
};
vector<Node> g(N); // g[u].fa[]表示u的父节点
vector<int> fa[N+1];
void dfs(int u,int x)
{
    dp[u]=x;
    if(g[u].son.size()==0) return;
    for(auto ns:g[u].son)
    {
        dfs(ns,x+g[ns].v);
    }
}
int main()
{
    int n;
    cin>>n>>s;
    dp[0]=0;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        g[i].v=x;
        dp[i]=-1;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].son.push_back(v);
        fa[v].push_back(u);
    }
    fa[1].push_back(0);
    int ans=0;
    dfs(1,g[1].v);
    for(int i=1;i<=n;i++)
    {
        int ni=i;
        while(fa[ni].size())
        {
            int tmp=dp[i]-dp[fa[ni][0]]; 
            if(tmp==s) ans++;
            ni=fa[ni][0];
            if(tmp>=s) break;
        }
    }
    cout<<ans;
}