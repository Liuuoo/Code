#include<bits/stdc++.h>
using namespace std;
const int MX=pow(2,31)-1;

int min_len[10100];
bool vis[10100];
struct Node
{
    int n;
    int ln;
};
struct D
{
    bool operator() (Node i,Node j)
    {
        return i.ln>j.ln;
    }
};
vector<vector<Node>> vec(1e4+10);
bool cmp(Node i,Node j)
{
    return i.ln<j.ln;
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)min_len[i]=MX;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
    }
    min_len[s]=0;
    priority_queue<Node,vector<Node>,D> pq;
    pq.push({s,0});
    while(!pq.empty())
    {
        Node fr=pq.top();
        int nn=fr.n;
        pq.pop();
        if(!vis[nn])
        {
            min_len[nn]=fr.ln;
            vis[nn]=true;
            for(auto x:vec[nn])
            {
                pq.push({x.n,x.ln+fr.ln});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<min_len[i]<<" ";
    }
}