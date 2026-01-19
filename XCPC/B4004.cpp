#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int m=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(m%a[i]!=0)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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