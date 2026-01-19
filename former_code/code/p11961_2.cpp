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
signed main()
{
    cout<<pow(2,3,100);
}