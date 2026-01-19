#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int kx,ky,dx,dy;
    cin>>n>>kx>>ky>>dx>>dy;
    int ans=0;
    if(dx>kx)
    {
        ans=max(dx,ans);
    }
    else if(dx<kx)
    {
        ans=max(ans,n-dx);
    }
    if(dy>ky)
    {
        ans=max(ans,dy);
    }
    else if(dy<ky)
    {
        ans=max(ans,n-dy);
    }
    cout<<ans<<'\n';
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