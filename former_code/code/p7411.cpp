#include<bits/stdc++.h>
using namespace std;
short bod[5000][5000]; //0 未涂 1-被迫加入 2-题目加入
int xx[]={0,0,1,-1,0};
int yy[]={1,-1,0,0,0};
bool vaild(int x,int y)
{
    return (x>=0&&y>=0);
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        x+=1100;
        y+=1100;
        if(bod[x][y]==1)
        {
            ans--;
        } 
        bod[x][y]=2;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            // 对周围四个点以及当前点是否有影响
            for(int i=0;i<5;i++)
            {
                int nx=f.first+xx[i];
                int ny=f.second+yy[i];
                if(bod[nx][ny])
                { //有值才能有影响 
                    //影响多少个
                    int cnt=0;
                    for(int j=0;j<4;j++)
                    {
                        int nnx=nx+xx[j];
                        int nny=ny+yy[j];
                        if(bod[nnx][nny])
                        {
                            cnt++;
                        }
                    }
                    if(cnt==3)
                    {
                        for(int j=0;j<4;j++)
                        {
                            int nnx=nx+xx[j];
                            int nny=ny+yy[j];
                            int cnt=0;
                            if(!bod[nnx][nny])
                            {
                                bod[nnx][nny]=1;
                                q.push({nnx,nny});
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}