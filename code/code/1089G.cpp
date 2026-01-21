#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[61];

bool jud(int x,int n)
{
    int res=0;
    for(int i=0;i<21;i++)
    {
        int j=i;
        int cnt=0;
        int tmp=0;
        while(cnt<x&&j<21)
        {
            tmp+=a[j++];
            cnt++;
        }
        res=max(res,tmp);
    }
    return res>=n;
}

void solve()
{
    int n;
    cin>>n;
    int w=0;
    for(int i=0;i<7;i++) 
    {
        cin>>a[i];
        if(a[i]==1)
        {
            w++;
        }
    }
    for(int i=7;i<14;i++) a[i]=a[i-7];
    for(int i=14;i<21;i++) a[i]=a[i-7];
    int ans=0;
    n-=w;
    if(n>0)
    {
        ans+=(n/w)*7;
        n%=w;
    }
    n+=w;
    // cout<<ans<<'\n';
    for(int i=0;i<14;i++)
    {
        if(jud(i,n))
        {
            cout<<ans+i<<endl;
            return;
        }
    }
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