#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;

    vector<int>a(2*n+1);
    vector<int>b(2*n);

    for(int i=1;i<=2*n;i++) cin>>a[i];

    for(int i=1;i<2*n;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    
    vector<int>pre_sum(n+1);
    vector<int>las_sum(n+1);

    for(int i=1;i<=n;i++) pre_sum[i]+=pre_sum[i-1]+i*b[i];
    int t=1;
    for(int i=2*n-1;i>=n;i--)
    {
        las_sum[t]=las_sum[t-1]+t*b[i];
        t++;
    }

    vector<int>odd(2*n+1);
    vector<int>even(2*n+1);

    for(int i=1;i<2*n;i+=2)
    {
        odd[i]+=odd[i-1]+b[i];
        odd[i+1]=odd[i];
    }

    for(int i=2;i<2*n;i+=2)
    {
        even[i]+=even[i-1]+b[i];
        even[i+1]=even[i];
    }

    for(int i=1;i<=n;i++)
    {
        int ans=pre_sum[i]+las_sum[i];
        if(i%2==1)
        {
            ans+=i*(odd[2*n-i-1]-odd[i]);
            ans+=(i-1)*(even[2*n-i-1]-even[i]);
        }
        else 
        {
            ans+=(i-1)*(odd[2*n-i-1]-odd[i]);
            ans+=i*(even[2*n-i-1]-even[i]);
        }
        cout<<ans<<" ";
    }
    cout<<'\n';
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