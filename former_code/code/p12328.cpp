#include<bits/stdc++.h>
using namespace std;

int n;
const int N=55;
int A[N][N];
int B[N][N];

int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};

void change()
{
    int C[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            C[j][n-i+1]=B[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            B[i][j]=C[i][j];
            // cout<<C[i][j]<<" ";
        }
        // cout<<'\n';
    }
    // cout<<'\n';
}

bool vaild(int x,int y)
{
    return (x>=1&&y>=1&&x<=n&&y<=n);
}
bool vaild2(int x,int y)
{
    return {x>=n+1&&y>=n+1&&x<=2*n&&y<=2*n};
}

int bfs(map<pair<int,int>,set<pair<int,int>>> g)
{
    int res=0;
    map<pair<int,int>,bool> vis;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[{i,j}]) continue;
            else if(A[i][j]==0) continue; 
            else 
            {
                int tmp=0;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[{i,j}]=true;
                while(!q.empty())
                {
                    auto f=q.front();
                    q.pop();
                    tmp++;
                    for(auto it:g[f])
                    {
                        if(vis[{it.first,it.second}]) continue;
                        if(vaild(it.first,it.second))
                        {
                            if(A[it.first][it.second])
                            {
                                q.push(it);
                                vis[{it.first,it.second}]=true;
                            }
                        }
                        else if(vaild2(it.first,it.second))
                        {
                            if(B[it.first-n][it.second-n])
                            {
                                q.push(it);
                                vis[{it.first,it.second}]=true;
                            }
                        }
                        else {}
                    }
                }
                res=max(res,tmp);
            }
        }
    }
    return res;
}

int calc(map<pair<int,int>,set<pair<int,int>>> g)
{
    map<pair<int,int>,set<pair<int,int>>> t=g;
    int res=0;
    for(int ii=0;ii<4;ii++)
    {
        change();
        // 以下是四个边,上右下左
        for(int i=1;i<=n;i++) // B的位移量
        {
            for(int j=1;j<=i;j++)
            {
                g[{1,n-i+j}].insert({2*n,n+j});
            }
            res=max(res,bfs(g));
            g=t;
        }
        for(int i=1;i<=n;i++) // B的位移量
        {
            for(int j=1;j<=i;j++)
            {
                g[{1,j}].insert({2*n,2*n-i+j});
            }
            res=max(res,bfs(g));
            g=t;
        }

        // 右
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[{j,n}].insert({2*n-i+j,1});
            }
            res=max(res,bfs(g));
            g=t;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[{n-i+j,n}].insert({n+j,1});
            }
            res=max(res,bfs(g));
            g=t;
        }

        // 下
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[{n,j}].insert({n+1,2*n-i+j});
            }
            res=max(res,bfs(g));
            g=t;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[{n,n-i+j}].insert({n+1,n+j});
            }
            res=max(res,bfs(g));
            g=t;
        }

        // left
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[{j,1}].insert({2*n-i+j,2*n});
            }
            res=max(res,bfs(g));
            g=t;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                g[{n-i+j,1}].insert({n+j,2*n});
            }
            res=max(res,bfs(g));
            g=t;
        }
    }
    return res;
}

int main()
{
    map<pair<int,int>,set<pair<int,int>>> g;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            A[i][j]=x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            B[i][j]=x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<4;k++)
            {
                int nx=i+xx[k];
                int ny=j+yy[k];
                if(vaild(nx,ny))
                {
                    g[{i,j}].insert({nx,ny});
                    // g2[{i,j}].push_back({nx,ny});
                }
            }
            for(int k=0;k<4;k++)
            {
                int nx=n+i+xx[k];
                int ny=n+j+yy[k];
                if(vaild2(nx,ny))
                {
                    g[{n+i,n+j}].insert({nx,ny});
                }
            }
        }
    }
    int ans=bfs(g); //one A map
    map<pair<int,int>,bool> vis;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[{i,j}]) continue;
            else if(B[i][j]==1)
            {
                int tmp=0;
                queue<pair<int,int>>q;
                q.push({i,j});
                vis[{i,j}]=true;
                while(!q.empty())
                {
                    auto f=q.front();
                    q.pop();
                    tmp++;
                    for(int i=0;i<4;i++)
                    {
                        int nx=f.first+xx[i];
                        int ny=f.second+yy[i];
                        if(vaild(nx,ny)&&B[nx][ny]==1&&!vis[{nx,ny}])
                        {
                            q.push({nx,ny});
                            vis[{nx,ny}]=1;
                        }
                    }
                }
                ans=max(ans,tmp);
            }
        }
    }
    cout<<max(ans,calc(g));
}