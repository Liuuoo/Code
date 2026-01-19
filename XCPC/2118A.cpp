#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int tmp=n-k-1;
    if(k>0)cout<<1;
    for(int i=0;i<tmp;i++)cout<<0;
    for(int i=0;i<k-1;i++) cout<<1;
    if(tmp>=0) cout<<0;
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