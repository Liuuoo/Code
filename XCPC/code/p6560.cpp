#include<bits/stdc++.h>
using namespace std;
const int N=12345;
vector<int>fro[N];
vector<int>bac[N];
int jud=0;

void jud_cyc()
{
    
}

void bfs(int s,int t)
{
    int vis[N]={0};
    queue<int>q;
    q.push(t);
    vis[t]=1;

    while(!q.empty())
    {
        int now_node=q.front();
        for(auto x:bac[now_node])
        {
            // cout<<x<<"\n";
            if(vis[x]==0)
            {
                vis[x]=-1*vis[now_node];
            }
            else
            {
                if(vis[x]==-1)
                {
                    if(vis[now_node]==-1)
                    {
                        vis[x]=1;
                    }
                }
            }
            if(x!=s) q.push(x);
        }
        q.pop();
    }
    // for(int i=s;i<=t;i++) 
    // cout<<vis[i]<<" ";

}


int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        fro[x].push_back(y);
        bac[y].push_back(x);
    }

    while(q--)
    {
        jud=0;
        int s,t;
        cin>>s>>t;
        bfs(s,t);
    }
}