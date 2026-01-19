#include<bits/stdc++.h>
using namespace std;
string s="$ABCDEFGHI";
int n,m;
const int N=110;
int box[N][N];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};

int fid(int x,int y) 
{
    bool vis[27]={false};
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx<1||ny<1||nx>n||ny>m) continue;
        int c=box[nx][ny];
        if(c) 
        {
            vis[c]=true;
        }
    }
    for(int i=1;i<=26;i++)
    {
        if(!vis[i]) return i;
    }
}

void draw(int x,int y)
{
    int nx=x,ny=y;
    int color=fid(x,y);
    while(nx<=n&&ny<=m)
    {   
        nx++;
        ny++;
        int R=fid(x,ny);
        int D=fid(nx,y);
        if(R!=color||D>color||box[x][ny]||box[nx][y]) 
        {
            break;
        }
    }
    nx--;
    ny--;
    for(int i=x;i<=nx;i++)
    {
        for(int j=y;j<=ny;j++)
            box[i][j]=color;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(box[i][j]) continue;
            draw(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int c=box[i][j];
            cout<<s[c];
        }
        cout<<'\n';
    }
}