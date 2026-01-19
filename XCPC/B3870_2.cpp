#include <bits/stdc++.h>
using namespace std;
int xx[]={-1,1,0,0};
int yy[]={0,0,-1,1};
const int N=1e4+10;
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
			cin>>bod[i][j];
	}
	int ans=0;
	 int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt=0;
			if(bod[i][j]=='#') 
			{
				bod[i][j]='.';
				for(int k=1;k<=n;k++)
                {
                    for(int l=1;l<=m;l++)
                    {
                        if(bod[k][l]=='.'&&jud(k,l)) cnt++;
                    }
                }
				bod[i][j]='#';
			}
			ans=max(ans,cnt);
		}
	 } 

	 cout<<ans;
	return 0;
}