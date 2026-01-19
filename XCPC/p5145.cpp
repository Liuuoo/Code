#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
pair<int,int> g[N];
int dp[N];

int dis(int x)
{
    int sum=0;
    int nx=x;
    while(g[nx].first!=x)
    {
        sum+=g[nx].second;
        nx=g[nx].first;
    }
    sum+=g[nx].second;

    nx=x;
    while(g[nx].first!=x)
    {
        dp[nx]=sum;
        nx=g[nx].first;
    }
    dp[nx]=sum;
    return sum;
}

// int bfs(int x)
// {
//     queue<int>q;
//     q.push(x);
//     while(!q.empty())
//     {
//         int f=q.front();
//         if(vis[f])
//         {
//             if(dp[f]!=-1) return dp[f];
//             else 
//             {
//                 dp[x]=dis(f);
//                 return dp[f];
//             }
//         }
//         else vis[f]=true;
//         q.pop();
//         q.push(g[f].first);
//     }
// }

int dfs(int x)
{
    if(dp[x]!=-1) return dp[x];
    if(vis[x]) return dp[x]=dis(x);
    vis[x]=true;
    return dp[x]=dfs(g[x].first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        int x,y;
        cin>>x>>y;
        g[i]={x,y};
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        else ans=max(ans,dfs(i));
    }
    cout<<ans;
}
// 7
// 2 1
// 3 1
// 1 1
// 1 1
// 4 1
// 2 1
// 3 1