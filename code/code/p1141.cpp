#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char bod[N][N];
bool vis[N][N];
int cnt[N*N];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};

struct UF
{
    vector<int> fa;
    UF(int n)
    {
        fa.resize(n+10);
        for(int i=0;i<=n;i++) fa[i]=i;
    }
    int find(int x)
    {
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    void unity(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        else 
        {
            fa[x]=y;
        }
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    UF uf(n*n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>bod[i][j];
        }
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        int num=(x-1)*n+y;
        if(vis[x][y]) 
        {
            cout<<cnt[uf.find(num)]<<'\n';
        }
        else
        {
            int tmp=0;
            queue<pair<int,int>> q;
            q.push({x,y});
            vis[x][y]=true;
            while(!q.empty())
            {
                tmp++;
                pair<int,int>p=q.front();
                q.pop();
                int fx=p.first,fy=p.second;
                for(int i=0;i<4;i++)
                {
                    int nx=fx+xx[i];
                    int ny=fy+yy[i];
                    if(!vis[nx][ny]&&bod[nx][ny]!=bod[fx][fy]&&nx>=1&&nx<=n&&ny>=1&&ny<=n)
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                        int nnum=(nx-1)*n+ny;
                        uf.unity(num,nnum);
                    }   
                }
            }
            cnt[uf.find(num)]=tmp;
            cout<<tmp<<'\n';
        }
    }
}