#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
int a[N];
int pre_sum[N];
vector<int> vec;
int n,k,p;
signed main()
{
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    pre_sum[0]=0;

    for(int i=1;i<=n;i++)
    {
        pre_sum[i]=(pre_sum[i-1]+a[i])%p;
    }
    set<int> S;
    S.insert(0);
    int ans=INT64_MAX;
    for(int i=1;i<=n;i++)
    {
        int tmp=pre_sum[i];
        if(pre_sum[i]<k)
        {
            tmp+=p-(*--S.upper_bound((pre_sum[i]-k+p)%p));
        }
        else 
        {
            tmp+=-(*--S.upper_bound((pre_sum[i]-k+p)%p));
        }
        S.insert(pre_sum[i]);
        ans=min(ans,tmp);
    }
    cout<<ans;
}