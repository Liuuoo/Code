#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<pair<int,int>> vec;

bool cmp(pair<int,int>i, pair<int,int>j)
{
    return i.first>j.first;
}

signed main()
{
    int n;
    cin>>n;
    int mx=INT64_MIN;
    int mi=INT64_MAX;
    pair<int,int> p;
    int aa,bb;
    cin>>aa>>bb;
    p={aa,bb};
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(a==-1&&b==-1) break;
        mx=max(mx,a);
        mi=min(mi,a);
        vec.push_back({a,b});
    }
    int del;
    cin>>del;
    sort(vec.begin(),vec.end());
    int nun=vec.back().second;
    int pic=vec.back().first;
    while(nun>=0)
    {
        nun-=del;
        pic++;
        vec.push_back({pic,nun});
    }

    int np;
    for(auto &x:vec)
    {
        if(x.first==n) np=(x.first-p.first)*x.second;
        x.first-=p.first;
        cout<<x.first<<" "<<x.second<<'\n';
    }
    int mx_prc=INT64_MIN;
    for(auto &x:vec)
    {
        mx_prc=max(mx_prc,x.first*x.second);
    }

    cout<<mx_prc<<" "<<np;
    if(mx_prc==np)
    {

    }
    else 
    {
        
    }
    // cout<<((mx_prc-np)+p.second-1)/p.second;
}