#include<bits/stdc++.h>
using namespace std;
int a,b;
const int N=10;
long long ans=0;
bool vis[N][N];

int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};

void dfs(int x,int y)
{
    if(x==a||y==b||x==0||y==0) 
    {
        // cout<<x<<" "<<y<<'\n';
        ans++;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(!vis[nx][ny])
        {
            vis[nx][ny]=true;
            dfs(nx,ny);
            vis[nx][ny]=false;
        }
    }
}

int main()
{
    cin>>a>>b;
    for(int i=1;i<a;i++)
    {
        memset(vis,0,sizeof(vis));
        vis[i][0]=true;
        vis[i][1]=true;
        // cout<<i<<" "<<1<<"\n"<<'\n';
        dfs(i,1);
        // cout<<'\n';
    }
    for(int i=1;i<b;i++)
    {
        memset(vis,0,sizeof(vis));
        vis[0][i]=true;
        vis[1][i]=true;
        dfs(1,i);
    }
    cout<<ans*2;
}