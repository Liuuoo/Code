#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
char bod[N][N];
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};
int n,m;

bool jud1(int x,int y)
{  
    if(x<1||x>n||y<1||y>m) return false;
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
        {
            if(bod[nx][ny]=='#') return false;
        }
    }
    return true;
}

int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            bod[i][j]=c;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(bod[i][j]=='.'&&jud1(i,j))
            {
                ans++;
            }
          
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int tmp=ans;
            if(bod[i][j]=='#')
            {
                bod[i][j]='.';
                if(jud1(i,j)) 
                {
                    tmp++;
                }
                for(int k=0;k<4;k++)
                {
                    int nx=i+xx[k];
                    int ny=j+yy[k];
                    if(bod[nx][ny]=='.'&&jud1(nx,ny)) tmp++;
                }
                bod[i][j]='#';
            }

            cnt=max(cnt,tmp);
        }
    }
    cout<<cnt;
}