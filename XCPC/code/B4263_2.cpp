#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
char bod[N][N];
int n,m;

bool jud(int x,int y)
{
	for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(bod[nx][ny]=='#') return false;
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
	int ini=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
            if(bod[i][j]=='.') ini+=jud(i,j);
		}
	}

	int ans=ini;
	// cout<<ini<<'\n';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int tmp=ini;
            if(bod[i][j]=='#')
            {
                bod[i][j]='.';
                if(jud(i,j)) tmp++;
                for(int k=0;k<4;k++)
                {
                    int nx=i+xx[k];
                    int ny=j+yy[k];
                    if(nx<1||ny<1||nx>n||ny>m)  continue;
                    
                    if(bod[nx][ny]=='.'&&jud(nx,ny)) tmp++;
                }
                bod[i][j]='#';
            }
            ans=max(ans,tmp);
        }
    }
	cout<<ans;
}