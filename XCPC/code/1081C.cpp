#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
inline int ksm(int a,int b){int t=1;for(;b;b>>=1,a=a*a%mod)if(b&1)t=t*a%mod;return t%mod;}//快速幂
inline int C(int n,int m){//求组合数
    if(n<m)return 0;
    if(m>n-m)m=n-m;
    int a=1,b=1;
    for(int i=1;i<=m;i++)
        a=a*(n-i+1)%mod,b=b*i%mod;
    return a*ksm(b,mod-2)%mod;
}
signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int sum=m;
    int group=C(n-1,k);
    int ans=((group%mod)*((m*ksm(m-1,k))%mod))%mod;
    cout<<ans;
}