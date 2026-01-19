#include<bits/stdc++.h>
using namespace std;
int xx[]={0,0,1,-1,0};
int yy[]={1,-1,0,0,0}; //5-太傻了自己gg了
int bod[20][20];
bool vaild(int x,int y) {return (x>=1&&x<=19&&y>=1&&y<=19);}
bool vis[20][20];

bool dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(!vaild(nx,ny)||vis[nx][ny]) continue;
        if(bod[nx][ny] == 0) return true; //有气
        else 
        {
            if(bod[nx][ny]==bod[x][y]) 
            {
                if(dfs(nx,ny)) return true;
            }
        }
    }
    return false; //从来没有，返回false
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int ii=1;ii<=n;ii++)
    {
        int x,y;
        cin>>x>>y;
        int c;
        if(ii%2==1) c=1;
        else c=2;
        bod[x][y]=c;
        int ans=0;
        for(int i=0;i<4;i++) // 优先找别人 
        {
            memset(vis,0,sizeof(vis));
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(vaild(nx,ny)&&bod[nx][ny]&&bod[nx][ny]!=bod[x][y])
            {
                if(!dfs(nx,ny))
                {
                    for(int i=1;i<=19;i++)
                    {
                        for(int j=1;j<=19;j++)
                        {
                            if(vis[i][j]) 
                            {
                                ans++;
                                bod[i][j]=0;
                            }
                        }
                    }
                }
            }
        }

        // 自己
        int cnt=0;
        int i=4;
        int nx=x+xx[i];
        int ny=y+yy[i];

        if(!dfs(nx,ny))
        {
            memset(vis,0,sizeof(vis));
            if(!dfs(nx,ny))
            {
                for(int i=1;i<=19;i++)
                {
                    for(int j=1;j<=19;j++)
                    {
                        if(vis[i][j]) 
                        {
                            cnt++;
                            bod[i][j]=0;
                        }
                    }
                }
            }
        }
        if(ii%2==1) 
        {
            cout<<cnt<<" "<<ans<<'\n';
        }
        else 
        {
            cout<<ans<<" "<<cnt<<"\n";
        }
    }
}