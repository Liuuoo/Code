#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,vector<pair<int,int>>>M;
map<pair<int,int>,bool> V;
bool bod[111][111];// 0未预备到 1预备到(可以到)
bool vis[111][111]; //到过了
bool light[111][111]; // 0不亮 1亮
int xx[]={1,-1,0,0};
int yy[]={0,0,-1,1};

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        M[{x,y}].push_back({u,v});
    }
    queue<pair<int,int>>q;
    q.push({1,1});
    light[1][1]=1;
    vis[1][1]=1;  
    bod[1][1]=1;
    while(!q.empty())
    {
        auto f=q.front();
        // cout<<f.first<<" "<<f.second<<'\n';
        q.pop();
        vis[f.first][f.second]=1;
        for(int i=0;i<4;i++)
        {
            int nx=f.first+xx[i];
            int ny=f.second+yy[i];
            if(nx>=1&&ny>=1&&nx<=n&&ny<=n&&!vis[nx][ny])
            {
                bod[nx][ny]=1;
                if(light[nx][ny]==1) //灯亮-可达-压入
                {
                    q.push({nx,ny});
                    vis[nx][ny]=1; //到达过
                }
            }
        }
        for(auto x:M[f]) //
        {
            light[x.first][x.second]=1; //亮灯
            if(vis[x.first][x.second]) continue;
            for(int i=0;i<4;i++) //检查灯是否之前可到达
            {
                int nx=xx[i]+x.first;
                int ny=yy[i]+x.second;
                if(nx>=1&&ny>=1&&nx<=n&&ny<=n)
                {
                    if(vis[nx][ny]==1) //到达过
                    {
                        q.push(x);
                        break;
                    }
                }
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         cout<<light[i][j];
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(light[i][j]==1) ans++;
        }
    }
    cout<<ans;
}