#include<bits/stdc++.h>
using namespace std;
int bod[110][11];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int n;
bool vaild(int x,int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=10);
}
int main()
{
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            char c;
            cin>>c;
            bod[i][j]=c-'0';
        }
    }
    while(1)
    {
        bool flag=false;
        bool vis[n+1][11]={false};
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=10;j++)
            {
                if(vis[i][j] || bod[i][j]==0) continue;
                int cnt=0;
                queue<pair<int,int>>q;
                vector<pair<int,int>> vec;
                q.push({i,j});
                vis[i][j]=1;
                vec.push_back({i,j});
                while(!q.empty())
                {
                    auto f=q.front();
                    q.pop();
                    cnt++;
                    int x=f.first,y=f.second;
                    for(int i=0;i<4;i++)
                    {
                        int nx=x+xx[i];
                        int ny=y+yy[i];
                        if(!vis[nx][ny]&&vaild(nx,ny)&&bod[nx][ny]==bod[x][y])
                        {
                            q.push({nx,ny});
                            vis[nx][ny]=1;
                            vec.push_back({nx,ny});
                        }
                    }
                }
                if(cnt>=k)
                {
                    for(auto x:vec)
                    {
                        bod[x.first][x.second]=0;
                    }
                }
                maxn=max(maxn,cnt);
            }
        }
        if(maxn>=k)
        {
            for(int j=1;j<=10;j++)
            {
                vector<int>vec;
                for(int i=n;i>=1;i--)
                {
                    if(bod[i][j]) vec.push_back(bod[i][j]);
                }
                while(vec.size()!=n) vec.push_back(0);
                int t=0;
                for(int i=n;i>=1;i--)
                {
                    bod[i][j]=vec[t++];
                }
            }
        }
        else break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<bod[i][j];
        }
        cout<<'\n';
    }
}