#include<bits/stdc++.h>
using namespace std;

short xx[]={0,0,1,-1};
short yy[]={1,-1,0,0};
struct Node 
{
    short x,y;
    vector<vector<short>> vec;
    bool operator<(const Node& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return vec < other.vec; // std::vector 已支持 operator<
    }
};

map<Node,int>dp;
map<Node,bool>vis;
map<pair<short,short>,vector<pair<short,short>>>M;
pair<short,short>st,ed;
short n,m;

int main()
{
    cin>>n>>m;
    vector<vector<short>>bod;
    bod.resize(n+1);

    for(short i=1;i<=n;i++)
    {
        bod[i].resize(m+1);
        for(short j=1;j<=m;j++)
        {
            char c;  cin>>c;
            if(c=='S') 
            {
                st={i,j};
                bod[i][j]=1;
            }
            else if(c=='T')
            {
                ed={i,j};
                bod[i][j]=1;
            }
            else if(c=='.') bod[i][j]=1;
            else bod[i][j]=0;
        }
    }
    short k; cin>>k;
    for(int i=1;i<=k;i++)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        M[{x,y}].push_back({u,v});
    }
    dp[{st.first,st.second,bod}]=0;
    // vis[{st.first,st.second,bod}]=true;

    queue<Node>q;
    q.push({st.first,st.second,bod});
    int ans=-1;
    while(!q.empty())
    {
        Node f=q.front();
        // cout<<f.x<<" "<<f.y<<'\n';
        q.pop();
        if(f.x==ed.first&&f.y==ed.second)
        {
            ans=dp[f];
            break;
        }
        if(vis[f]) continue;
        vis[f]=true;
        for(short i=0;i<4;i++)
        {
            short nx=f.x+xx[i];
            short ny=f.y+yy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&f.vec[nx][ny]==1)
            {
                vector<vector<short>> nvec=f.vec;
                if(M.find({nx,ny})!=M.end())
                {
                    for(auto x:M[{nx,ny}])
                    {
                        nvec[x.first][x.second]=(f.vec[x.first][x.second]==1?0:1);
                    }
                }
                q.push({nx,ny,nvec});
                dp[{nx,ny,nvec}]=dp[f]+1;
            }
        }
    }
    cout<<ans;
}