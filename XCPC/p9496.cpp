#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;
    cout<<((n&m)!=n)+((n&m)!=m)<<'\n';
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
