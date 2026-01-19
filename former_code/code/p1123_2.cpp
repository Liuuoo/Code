#include<bits/stdc++.h>
using namespace std;
const int N=10;
int bod[N][N];
bool vis[N][N];
int sum;
int n,m;
int ans=0;

int xx[]={0,0,1,1,1,-1,-1,-1};
int yy[]={1,-1,0,-1,1,0,-1,1};

bool jud(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx<1||ny<1||nx>n||ny>m) continue;
        if(vis[nx][ny]) return false;
    }
    return true;
}
                     
void dfs(int x,int y,int sum)
{
    ans=max(ans,sum);
    if(y>m)
    {
        x++;
        y=1;
    }
    if(x>n) return;
    if(!vis[x][y]&&jud(x,y))
    {
        vis[x][y]=1;
        dfs(x,y+1,sum+bod[x][y]);
        vis[x][y]=0;
    }
    dfs(x,y+1,sum);
}

void solve()
{
    
    sum=0;
    ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>bod[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(1,0,0); 
    cout<<ans<<'\n';
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}