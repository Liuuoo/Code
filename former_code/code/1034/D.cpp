#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int del=n-k;
    if(k<=n-k)
    {
        int o=0;
        for(auto x:s)
        {
            if(x=='1') o++;
        }
        if(o<=k) cout<<"Alice";
        else cout<<"Bob";
    }
    else 
    {
        cout<<"Alice";
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