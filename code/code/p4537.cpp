#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
int ans=0;
const int N=10;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
set<string> S;

void paint(int bod[][N])
{
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cout<<bod[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
}

bool meet(int bod[][N])
{
    string s1,s2;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            s1+=(bod[i][j]+'0');
            int num=bod[i][j];
            if(num==0) num=1;
            else num=0;
            s2+=(num+'0');
        }
    }
    // cout<<s1<<" "<<s2<<'\n';
    if(S.find(s1)==S.end()&&S.find(s2)==S.end())
    {
        // cout<<s1<<" "<<s2<<'\n';
        S.insert(s1);
        S.insert(s2);
        return true;
    } 
    else return false;
}

bool bfs(int bod[][N])
{
    string s1,s2;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            s1+=(bod[i][j]+'0');
            int num=bod[i][j];
            if(num==0) num=1;
            else num=0;
            s2+=(num+'0');
        }
    }
    // cout<<s1<<" "<<s2<<'\n';

    bool vis[N][N]={false};
    queue<pair<int,int>> q;
    int res1=0;
    q.push({1,1});
    vis[1][1]=true;
    res1++;
    while(!q.empty())
    {
        auto f=q.front();
        int x=f.first;
        int y=f.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(!vis[nx][ny]&&bod[nx][ny]==bod[x][y]&&nx>=1&&nx<=a&&ny>=1&&ny<=b)
            {
                q.push({nx,ny});
                vis[nx][ny]=true;
                res1++;
            }
        }
    }
    bool jud=false;
    int res2=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(bod[i][j]!=bod[1][1])
            {
                q.push({i,j});
                vis[i][j]=true;
                if(i==a||i==1||j==b||j==1) jud=true;
                res2=1;
                break;
            }
        }
        if(res2!=0) break;
    }

    while(!q.empty())
    {
        auto f=q.front();
        int x=f.first;
        int y=f.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(!vis[nx][ny]&&bod[nx][ny]==bod[x][y]&&nx>=1&&nx<=a&&ny>=1&&ny<=b)
            {
                q.push({nx,ny});
                vis[nx][ny]=true;
                if(nx==a||ny==b||nx==1||ny==1) jud=true;
                res2++;
            }
        }
    }
    // cout<<res1<<" "<<res2<<'\n';
    return(jud&&res1+res2==a*b);
}

void dfs(int x,int y,int bod[][N],int sum)
{
    if(y==b+1)
    {
        x++;
        y=1;
    }
    if(x==a+1) return;
    bod[x][y]=1;

    if(bfs(bod)&&meet(bod)) 
    {   
        ans++;
    }
    dfs(x,y+1,bod,sum+1);
    // paint(bod);
    bod[x][y]=0;
    if(bfs(bod)&&meet(bod)) 
    {   
        ans++;
        // paint(bod);
    }

    // paint(bod);
    dfs(x,y+1,bod,sum);
}

signed main()
{   
    cin>>a>>b;
    string s0,s1;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            s0+='0';
            s1+='1';
        }
    }
    S.insert(s0);
    S.insert(s1);

    int bod[N][N];
    memset(bod,0,sizeof(bod));
    dfs(1,1,bod,0);
    cout<<ans;
}