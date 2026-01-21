#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main()
{
    string s;
    cin>>s;
    int ans=0;
    int p=0;
    for(auto x:s)
    {
        if(x=='a')
        {
            ans=(ans+p+1)%mod;
        }
        if(x=='b') 
        {
            p=ans;
        }
    }
    cout<<ans;
}