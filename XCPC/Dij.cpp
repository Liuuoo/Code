#include<bits/stdc++.h>
using namespace std;
const int m=1e5+10;
const int INF=0x7fffffff;
int dis[m];
bool vis[m];
vector<pair<int,int>> vec[m];
struct D
{
    bool operator() (pair<int,int> i, pair<int,int> j)
    {
        return i.second>j.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,D> pq;
void ini() {
    for(int i=1;i<=m;i++) dis[i]=INF;
}
void Dij(int ini_data)
{   
    pq.push({ini_data,0});
    while(!pq.empty())
    {
        auto [n,ln]=pq.top();
        pq.pop();
        if(vis[n]) continue;
        vis[n]=true;
        dis[n]=ln;
        for(auto [nn,nln]:vec[n])
        {
            pq.push({nn,ln+nln});
        }
    }
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
    }
    ini();
    Dij(s);
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}

