#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> vec;
    vec.push_back({0,0});
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    int las=0;
    for(int i=1;i<vec.size();i++)
    {
        int del=vec[i].first-vec[i-1].first;
        int add=vec[i].second-vec[i-1].second;
        if(add>del)
        {
            cout<<"No\n";
            return;
        }
        else if(add==del)
        {
        }
        else 
        {
            if(vec[i].second!=0)
            {
                if(vec[i].second>del-1)
                {
                    cout<<"No\n";
                    return;
                }
            } 
        }
    }
    cout<<"Yes\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}