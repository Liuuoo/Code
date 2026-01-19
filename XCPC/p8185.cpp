#include<bits/stdc++.h>
using namespace std;
int n;
int a[12];
bool vis[12];
set<int> S[12];
bool ans=false;

void dfs(int x,string s)
{
    if(x==s.size())
    {
        for(int i=0;i<s.size();i++)
        {
            // cout<<a[i]<<" ";
            if(S[a[i]].find(s[i])==S[a[i]].end()) return;
        }
        // cout<<'\n';
        ans=true;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            a[x]=i;
            vis[i]=true;
            dfs(x+1,s);
            vis[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=6;j++)
        {
            char c;
            cin>>c;
            S[i].insert(c);
        }
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        ans=false;
        if(s.size()<=4) dfs(0,s);
        cout<<(ans==1?"YES\n":"NO\n");
    }
}