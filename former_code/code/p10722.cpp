#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> col(N);
map<int,bool> vis;
vector<int>g[N];
vector<int>op(N);

void dfs(int root,int cnt)
{
    vis[root]=true;
    if(cnt) col[root]=(col[root]==1?0:1);
    for(auto x:g[root])
    {
        if(vis[x]) continue;
        dfs(x,(cnt+op[x])%2);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        col[i]=c-'0';
    }

    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        op[x]++;
        op[x]%=2;
    }
    dfs(1,op[1]);
    for(int i=1;i<=n;i++) cout<<col[i];
}