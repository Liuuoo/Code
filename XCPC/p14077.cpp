#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<vector<int>>g;
bool vis[N];

struct DSU
{
    vector<int>fa;
    DSU(int n)
    {
        fa.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
    }
    int find(int x)
    {
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) {}
        else fa[y]=x;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DSU dsu(n);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto x:g[f])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                    dsu.merge(x,i);
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(dsu.find(i)==i)
        {
            cnt++;
        }
    }
    cout<<cnt-1;
}