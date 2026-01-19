#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n; cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=INT64_MAX;
    for(int i=0;i<n;)
    {
        int ii=i;
        int j=i+1;
        int cnt=1;
        while(j<n&&a[ii]==a[j])
        {
            cnt++;
            j++;
            ii++;
        }
        int sum=0;
        sum=i*a[i]+(n-(ii+1))*a[i];
        // cout<<sum<<" ";
        ans=min(ans,sum);
        i=j;
    }
    cout<<ans<<'\n';
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