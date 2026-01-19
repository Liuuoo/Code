#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> edge[N];
bool vis[N];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(1);
    vis[1]=true;
    int cnt=0;
    while(1)
    {
        int f=q.top();
        cout<<f<<" ";
        cnt++;
        if(cnt==n) break;
        q.pop();
        for(int i=0;i<edge[f].size();i++)
        {
            int node=edge[f][i];
            if(!vis[node])
            {
                q.push(node);
                vis[node]=true;
            }
        }
    }
}