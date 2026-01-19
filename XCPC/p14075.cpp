#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int dp[N]; //dp_i表示该位置能获取的最大价值
signed main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="$"+s;
    int v[n+1];
    for(int i=1;i<=n;i++) cin>>v[i];
    dp[1]=v[1];
    for(int i=1;i<=n;i++)
    {
        set<int>S;
        S.insert(s[i]);
        int cnt=0;
        int j=i-1;
        dp[i]=dp[i-1]+v[1];
        while(j>=1&&cnt<=26)
        {
            if(S.count(s[j])) break;
            S.insert(s[j]);
            dp[i]=max(dp[i],dp[j-1]+v[i-j+1]);
            cnt++;
            j--;
        }
    }
    cout<<dp[n];
}
