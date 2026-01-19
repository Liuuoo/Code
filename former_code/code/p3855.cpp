#include<bits/stdc++.h>
using namespace std;
int n,m;

struct Node 
{
    pair<int,int>p1;
    pair<int,int>p2;
    bool operator<(const Node other) const 
    {
        if(other.p1!=p1) return p1<other.p1;
        else return p2<other.p2;
    }
    bool operator==(const Node other) const
    {
        if(other.p1!=p1) return false;
        else return p2==other.p2;
    }
};

int xx1[]={0,0,1,-1};
int yy1[]={1,-1,0,0};

int xx2[]={0,0,1,-1};
int yy2[]={-1,1,0,0};

int main()
{
    cin>>n>>m;
    vector<vector<char>>bod(n+1);
    pair<int,int> s1,s2,t;
    for(int i=1;i<=n;i++)
    {
        bod[i].resize(m+1);
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            bod[i][j]=c;
            if(c=='T') t={i,j};
            else if(c=='G') s1={i,j};
            else if(c=='M') s2={i,j};
        }
    }
    Node ed={t,t};
    map<Node,bool> vis;
    map<Node,int> step;
    queue<Node> q;
    Node node={s1,s2};
    q.push(node);
    step[node]=0;
    vis[node]=true;

    auto change=[&](int nx,int ny,int x,int y)->pair<int,int>
    {
        if(bod[nx][ny]=='#')
        {
            return {x,y};
        }
        else if(bod[nx][ny]=='X') 
        {
            return {-1,-1};
        }
        else return {nx,ny};
    };

    auto bfs=[&]()->int
    {
        while(!q.empty())
        {
            Node f=q.front();
            // cout<<step[f]<<'\n';
            // cout<<f.p1.first<<" "<<f.p1.second<<"  "<<f.p2.first<<" "<<f.p2.second<<'\n';
            auto p1=f.p1;
            auto p2=f.p2;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx1=p1.first+xx1[i];
                int ny1=p1.second+yy1[i];
                
                int nx2=p2.first+xx2[i];
                int ny2=p2.second+yy2[i];

                pair<int,int>np1,np2;
                np1=change(nx1,ny1,p1.first,p1.second);
                np2=change(nx2,ny2,p2.first,p2.second);

                if(np1.first==-1||np2.first==-1) continue;

                Node tmp={np1,np2};
                if(!vis.count(tmp))
                {
                    q.push(tmp);
                    vis[tmp]=true;
                    step[tmp]=step[f]+1;
                    if(tmp==ed) return step[tmp];
                }
            }
        }
        return -1;
    };

    int ans=bfs();
    
    if(ans!=-1)
    {
        cout<<ans;
    }
    else cout<<"no";
}