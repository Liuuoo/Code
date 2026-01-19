#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<pair<int,int>,pair<int,int>>> vec;


bool jud(pair<pair<int,int>,pair<int,int>> p)
{
    int x,y,u,v;
    x=p.first.first;
    y=p.first.second;
    u=p.second.first;
    v=p.second.second;
    
}


signed main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        vec.push_back({{x,y},{u,v}});
    }
    int ans=0;
    for(auto x:vec)
    {
        if(jud(x)) ans++;
    }
    cout<<ans;
}