#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
const int N=210;
int n,d[N][N];

void floyd(int n,map<pair<int,int>,int> &d)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];

    vector<pair<int,int>> E;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        E.push_back({x,y});
        d[x][y]=min(d[x][y],z);
        d[y][x]=min(d[y][x],z);
    }

    vector<bool>hs(n+1);
    for(int i=0;i<n;i++)
    {
        map<pair<int,int>,int> d;
        hs[vec[i]]=true;
        for(auto j:E)
        {
            int x=j.first;
            int y=j.second;
            if(hs[x]&&hs[y])
            {
                d[{x,y}]=min(d[{x,y}],w[x][y]);
                d[{y,x}]=min(d[{y,x}],w[y][x]);
            }
        }
        floyd(n,d);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y,t;
        cin>>x>>y>>t;
        int idx=lower_bound(vec.begin(),vec.end(),t)-vec.begin();
        if(idx==-1||idx==n) 
        {
            cout<<-1<<'\n';
            continue;
        }
        else 
        {
            map<int,vector<int>> ng=g[idx];
        }
    }
}