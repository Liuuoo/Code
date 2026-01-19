#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)  cin>>a[i];
    int pre[n+1],suf[n+2];
    pre[0]=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        pre[i]=min(pre[i-1],a[i]);
    }
    suf[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        suf[i]=max(suf[i+1],a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[i]==a[i]||suf[i]==a[i]) 
        {
            cout<<1;
        }
        else cout<<0;
    }
    cout<<'\n';
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