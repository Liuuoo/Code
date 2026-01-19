#include<bits/stdc++.h>
using namespace std;
const int N=100;
int bod[N][N];
int n,m;
int xx[]={1,0,1,0};
int yy[]={0,1,1,0};
// 0123 上右下左
struct Node
{
    pair<int,int>p;
    int d;
};

struct D
{
    bool operator()(const Node&a,const Node &b) const
    {
        if(a.p.first!=b.p.first) return a.p.first<b.p.first;
        else if(a.p.second!=b.p.second) return a.p.second<b.p.second;
        else return a.d<b.d;
    }
};

Node calc1(Node x,int dd)
{
    Node res=x;
    int d=x.d;
    if(d==0) res.p.first-=dd;
    if(d==1) res.p.second+=dd;
    if(d==2) res.p.first+=dd;
    if(d==3) res.p.second-=dd;
    return res;
}

Node calc2(Node x)
{
    Node res=x;
    res.d--;
    res.d=(res.d+4)%4;
    return res;
}

Node calc3(Node x)
{
    Node res=x;
    res.d++;
    res.d=(res.d+4)%4;
    return res;
}

bool jud(Node nn)
{
    int x=nn.p.first;
    int y=nn.p.second;
    if(x<=0||y<=0||x>=n||y>=m) return false;
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(bod[nx][ny]==1) return false;
    }
    return true;
}

int main()
{
    memset(bod,0,sizeof(bod));
    map<Node,bool,D> vis;
    map<Node,int,D> step;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>bod[i][j];
        }
    }
    pair<int,int> st;
    pair<int,int> ed;

    int sx,sy,ex,ey; char c;
    cin>>sx>>sy>>ex>>ey>>c;
    int cc;
    if(c=='N') cc=0;
    if(c=='E') cc=1;
    if(c=='S') cc=2;
    if(c=='W') cc=3;
    st={sx,sy};
    ed={ex,ey};
    queue<Node> q;
    q.push({st,cc});

    vis[q.front()]=true;
    step[q.front()]=0;

    while(!q.empty())
    {
        auto f=q.front();
        if(f.p==ed)
        {
            break;
        }
        q.pop();
        vector<Node> vec;
        Node ini=f;

        for(int i=0;i<3;i++) 
        {
            ini=calc1(ini,1);
            if(!jud(ini)) break;
            vec.push_back(ini);
        }

        vec.push_back(calc2(f));
        vec.push_back(calc3(f));

        for(auto it:vec)
        {
            if(!vis[it]&&jud(it))
            {
                q.push(it);
                vis[it]=true;
                step[it]=step[f]+1;
            }
        }
    }
    int minx=INT_MAX;
    for(int i=0;i<4;i++)
    {
        Node tmp={ed,i};
        if(step[tmp]!=0)
        {
            minx=min(minx,step[tmp]);
        }
    }
    if(minx!=INT_MAX) 
    {
        cout<<minx;
    }
    else if(ed!=st) cout<<-1;
    else cout<<0; 
}