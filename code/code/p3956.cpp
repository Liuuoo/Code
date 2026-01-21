#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int bod[N][N];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
struct Node
{
    int x,y,c;
    int step;
    bool operator<(Node b) const 
    {
        if(step!=b.step) return step>b.step;
        else if(c!=b.c) return c>b.c;
        else if(x!=b.x) return x>b.x;
        else return y>b.y;
    }
};

signed main()
{
    map<pair<pair<int,int>,int>,int> dist;
    map<pair<pair<int,int>,int>,bool> vis;

    int m,n;
    cin>>n>>m;
    memset(bod,-1,sizeof(bod));
    while(m--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        bod[x][y]=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=-1;k<=1;k++)
            {
                dist[{{i,j},k}]=INT64_MAX;
            }
        }
    }
    priority_queue<Node>pq;
    pq.push({1,1,bod[1][1],0});
    dist[{{1,1},bod[1][1]}]=0;
    while(!pq.empty())
    {
        Node f=pq.top();
        pq.pop();
        if(vis[{{f.x,f.y},f.c}]) continue;
        vis[{{f.x,f.y},f.c}]=true;
        for(int i=0;i<4;i++)
        {
            int nx=f.x+xx[i];
            int ny=f.y+yy[i];
            int nc=bod[nx][ny];
            Node ne={nx,ny,nc,f.step};
            int clo=bod[f.x][f.y]; //原棋盘颜色 fc-改变后颜色
            if(nx>=1&&ny>=1&&nx<=n&&ny<=n) // 边界判定
            {
                if(clo==-1 && nc==-1) continue; //原白-下白
                else if(nc==f.c)  // 原==下!=白
                {
                    if(f.step<dist[{{nx,ny},nc}])
                    {
                        dist[{{nx,ny},nc}]=f.step;
                        pq.push(ne);
                    }
                }
                else //原!=下
                {
                    if(nc==-1) ne.step+=2,ne.c=clo,nc=clo;
                    else ne.step++;
                    if(f.step<dist[{{nx,ny},nc}])
                    {
                        dist[{{nx,ny},nc}]=ne.step;
                        pq.push(ne);
                    }
                }
            }
        }
    }
    // cout<<"\n\n";
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         int tmp=INT64_MAX;
    //         for(int k=-1;k<=1;k++)
    //         {
    //             tmp=min(tmp,dist[{{i,j},k}]);
    //         }
    //         if(tmp==INT64_MAX) cout<<"-1 ";
    //         else cout<<tmp<<" ";
    //     }
    //     cout<<'\n';
    // }

    int ans=INT64_MAX;
    for(int i=-1;i<=1;i++)
    {
        ans=min(ans,dist[{{n,n},i}]);
    }
    if(ans==INT64_MAX) cout<<-1;
    else cout<<ans;
}