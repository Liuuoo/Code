#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
set<int> g[N];
int step[N];
bool vis[N];

int main()
{
    memset(step,-1,sizeof(step));
    int n;
    cin>>n;
    n-=1;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }
    int x,a,b,c,d;
    cin>>x>>a>>b>>c>>d;
    g[a].erase(b);
    g[b].erase(a);
    g[c].insert(d);
    g[d].insert(c);
    queue<int> q;
    q.push(x);
    vis[x]=true;
    step[x]=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        if(f==1) break;
        set<int> tmp=g[f];
        for(auto x:tmp)
        {
            if(!vis[x])
            {
                vis[x]=true;
                step[x]=step[f]+1;
                q.push(x);
            }
        }
    }
    cout<<step[1];
}