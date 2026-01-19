#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main()
{
    int n,l,r;
    cin>>n>>l>>r;

    // int test[3]={0};
    // for(int i=l;i<=r;i++) test[i%3]++;

    int cnt[3]={0};
    while(l%3!=0&&l<=r)
    {
        cnt[l%3]++;
        l++;
    }
    while(r%3!=2&&l<=r)
    {
        cnt[r%3]++;
        r--;
    }
    cnt[0]+=((r-l+1)/3);
    cnt[1]+=((r-l+1)/3);
    cnt[2]+=((r-l+1)/3);

    // for(int i=0;i<3;i++) assert(cnt[i]==test[i]);

    int dp[n+1][3];
    memset(dp,0,sizeof(dp));
    dp[0][0]=cnt[0];
    dp[0][1]=cnt[1];
    dp[0][2]=cnt[2];   

    for(int i=1;i<n;i++)
    {
        dp[i][0]=((dp[i-1][0]*cnt[0])%mod+(dp[i-1][1]*cnt[2])%mod+(dp[i-1][2]*cnt[1])%mod)%mod;
        dp[i][1]=((dp[i-1][0]*cnt[1])%mod+(dp[i-1][1]*cnt[0])%mod+(dp[i-1][2]*cnt[2])%mod)%mod;
        dp[i][2]=((dp[i-1][0]*cnt[2])%mod+(dp[i-1][1]*cnt[1])%mod+(dp[i-1][2]*cnt[0])%mod)%mod;
    }
    cout<<dp[n-1][0]<<"\n";
}