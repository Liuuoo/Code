#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int l,r;
};

bool cmp(Node &i,Node&j)
{
    if(i.l!=j.l) return i.l<j.l;
    else  return i.r<j.r;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<Node>vec;
    while(n--)
    {
        int l,r,s;
        cin>>l>>r>>s;
        vec.push_back({l,s});
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans=k;
    for(auto x:vec)
    {
        if(ans<x.l) break;
        ans=max(ans,x.r);
    }
    cout<<ans<<'\n';
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
} 