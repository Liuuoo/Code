#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int>vec;
    int n,k;
    cin>>n>>k;
    while(n--)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int ini=vec[k-1];
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int st;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]==ini) 
        {
            st=i;
            break;
        }
    }
    int time=0;
    int r=ini;
    for(int i=st;i<vec.size()-1;i++)
    {
        int del=vec[i+1]-vec[i];
        if(r-time<del) 
        {
            cout<<"NO\n";
            return;
        }
        r=vec[i+1];
        time+=del;
    }
    cout<<"YES\n";
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