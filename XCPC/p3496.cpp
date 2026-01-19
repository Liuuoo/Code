#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> g[n+1];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==0)
        {
            cout<<"NIE\n";
            return 0;
        }
    }
    cout<<"TAK\n";
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) continue;
        else 
        {
            queue<int>q;
            q.push(i);
            ans[i]=1;
            while(!q.empty())
            {
                int f=q.front();
                q.pop();
                for(auto x:g[f])
                {
                    if(!ans[x])
                    {
                        ans[x]=ans[f]*-1;
                        q.push(x);
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==1) cout<<"K\n";
        else cout<<"S\n";
    }
}