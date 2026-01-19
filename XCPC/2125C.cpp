#include<bits/stdc++.h>
using namespace std;
#define int long long
int calc(int l,int r,int x)
{
    int R=r/x;
    int L=(l-1)/x;
    return R-L;
}
int fac(vector<int>&a,int l,int r)
{
    int g=1;
    for(int i=0;i<a.size();i++)
    {
        g=__gcd(g,a[i])*g*a[i];
    }
    return calc(l,r,g);
}
void solve()
{
    int l,r;
    cin>>l>>r;
    int ans=0;
    vector<int>b={2,3,5,7};
    for(int state=0;state<(1<<4);state++)
    {
        if(state==0)continue;
        vector<int>has;
        for(int bit=0;bit<4;bit++)
        {
            if(state>>bit&1)has.push_back(b[bit]);
        }
        if(has.size()%2==1)ans+=fac(has,l,r);
        else ans-=fac(has,l,r);
    }
    cout<<(r-l+1)-ans<<"\n";
    // int l,r;
    // cin>>l>>r;
    // int _2,_3,_5,_7,_6,_10,_14,_15,_21,_35,_30,_105,_210;
    // _2=calc(l,r,2);
    // _3=calc(l,r,3);
    // _5=calc(l,r,5);
    // _7=calc(l,r,7);
    // _6=calc(l,r,6);
    // _10=calc(l,r,10);
    // _14=calc(l,r,14);
    // _15=calc(l,r,15);
    // _21=calc(l,r,21);
    // _35=calc(l,r,35);
    // _30=calc(l,r,30);
    // _105=calc(l,r,105);
    // _210=calc(l,r,210);
    // int ans=_2+_3+_5+_7-(_6+_10+_14+_15+_21+_35)+(_30+_105)-_210;
    // cout<<(r-l+1)-ans<<'\n';
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