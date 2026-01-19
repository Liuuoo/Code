#include<bits/stdc++.h>
using namespace std;
#define int long long

int pow(int a,int b,int mod)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res=res*a%mod;
            res%=mod;
        }
        a=a*a%mod;
        b=(b>>1);
    }
    return res%mod;
}

void solve()
{
    int a,p;
    cin>>a>>p;
    if(pow(a,p-1,p)!=1)
    {
        cout<<"No\n";
        return;
    }
    vector<int>S;
    S.push_back(1);
    for(int i=2;i*i<=p-1;i++)
    {
        if((p-1)%i==0) 
        {
            S.push_back(i);
            S.push_back((p-1)/i);
        }
    }
    for(auto x:S)
    {
        if(pow(a,x,p)==1) 
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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