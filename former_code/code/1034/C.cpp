#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int ini=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==k) ini=a[i];
    }
    sort(a+1,a+n+1);
    int time=0;
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==ini) 
        {
            t=i;
            break;
        }
    }
    for(int i=t;i<n;i++)
    {
        int del=a[i+1]-a[i];
        if(time+del>ini)
        {
            cout<<"NO\n";
            return;
        }
        else 
        {
            time+=del;
            ini=a[i+1];
        }
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