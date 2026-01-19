#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,s,t;
    cin>>n>>s>>t;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(s!=t) cout<<((a[s]^a[t])+(a[s]|a[t])+(a[s]&a[t]));
    else cout<<"0";
    cout<<'\n';
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