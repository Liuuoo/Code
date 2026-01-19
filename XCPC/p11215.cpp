#include<bits/stdc++.h>
using namespace std;
const int N=3100;


struct Node
{
    short data; // 0 1-lake 2-tree
    int time;
};

Node bod[N][N];
bool vis[N][N]; // vis为通过扩张新加入的树
int step[N][N]; // 有step的都可以存活


int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int n,m,q,r,k;

bool vaild(int x,int y)
{
    return (x>=1&&y>=1&&x<=n&&y<=m);
}

int main()
{
    cin>>n>>m>>q>>r>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            step[i][j]=INT_MAX;
        }
    }
    map<pair<int,int>,vector<pair<int,int>>> M;
    while(q--)
    {
        int a,b,u,v;
        cin>>a>>b>>u>>v;
        for(int i=a;i<=u;i++)
        {
            for(int j=b;j<=v;j++)
            {
                bod[i][j]={1,-1}; // 强行覆盖
            }
        }
    }
    while(r--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        bod[x][y].time=t;
        // step[x][y]=t; //题目保证不会有重叠树

        bod[x][y].data=2;

        // bool more=false;
        for(int i=0;i<4;i++) // 周围四个
        {
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(vaild(nx,ny))
            {
                // if(bod[nx][ny].data==1)
                // { 
                //     continue;
                // }
                if(bod[nx][ny].data==2)
                {
                    if(step[nx][ny]!=INT_MAX)
                    {
                        if(t+k>=step[nx][ny])
                        step[x][y]=t;
                    }
                    else
                    {
                        if(t<=bod[nx][ny].time+k)
                        {
                            step[nx][ny]=bod[nx][ny].time;
                            step[x][y]=t;
                        }
                    }
                }
                // more=1;
                int nnx=nx+xx[i]; // FRONT AGAIN
                int nny=ny+yy[i];   
                if(bod[nnx][nny].data==1||bod[nx][ny].data==1) // lake-nx,ny can live
                {
                    queue<pair<int,int>> q;
                    q.push({nx,ny});
                    step[x][y]=t;
                    step[nx][ny]=step[x][y]+1;
                    vis[nx][ny]=1;
                    vis[x][y]=1;
                    while(!q.empty())
                    {
                        auto f=q.front();
                        int x=f.first,y=f.second;
                        q.pop();
                        for(int i=0;i<4;i++)
                        {
                            int nx=x+xx[i];
                            int ny=y+yy[i];
                            if(vaild(nx,ny)&&!vis[nx][ny]&&bod[nx][ny].data!=1)
                            {
                                bool lake=false;
                                for(int j=0;j<4;j++)
                                {
                                    int nnx=nx+xx[j];
                                    int nny=ny+yy[j];
                                    if(vaild(nnx,nny)&&bod[nnx][nny].data==1) 
                                    {
                                        lake=true;
                                        break;
                                    }
                                }
                                if(lake)
                                {
                                    if(bod[nx][ny].data==0)
                                    {
                                        step[nx][ny]=min(step[nx][ny],step[x][y]+1);
                                    }
                                    if(bod[nx][ny].data==2)
                                    {
                                        step[nx][ny]=min(step[nx][ny],bod[nx][ny].time);
                                    }
                                    q.push({nx,ny});   
                                    vis[nx][ny]=true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(step[i][j]!=INT_MAX) ans++;
            // else cout<<"0";
        }
        // cout<<'\n';
    }
    cout<<ans;
}