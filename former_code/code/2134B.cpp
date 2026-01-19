#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int n;
int arr[100005];
int solve1()
{
    int a[15];
    for(int i=1;i<=n;i++) 
    {
        a[i]=arr[i];
    }
    a[n+1]=INT64_MAX;
    int ans=max(0ll,a[1]-a[2]);
    if(a[1]>a[2]) a[1]=a[2];
    for(int i=3;i<=n;i+=2)
    {
        if(a[i]+a[i-2]>a[i-1])
        {
            ans+=a[i]+a[i-2]-a[i-1];
            a[i]-=(a[i]+a[i-2]-a[i-1]);
            if(a[i]>a[i+1])
            {
                ans+=a[i]-a[i+1];
                a[i]=a[i+1];
            }
        }
        if(a[i]>a[i+1])
        {
            ans+=a[i]-a[i+1];
            a[i]=a[i+1];
        }
    }
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return ans;
}
int solve2() {
    // cin >> n;
    int a[15];
    for (int i = 1; i <= n; i++) a[i] = arr[i];
    a[n + 1] = 0;
    ll cnt = 0;
    for (int i = 2; i <= n; i += 2)
    {
        if (a[i] < a[i - 1] + a[i + 1])
        {
            int t = a[i - 1] + a[i + 1] - a[i];
            cnt += t;
            if (t > a[i + 1])  a[i + 1] = 0, t -= a[i + 1];
            else a[i + 1] -= t, t = 0;
            a[i - 1] -= t;
        }
    }
    return cnt;
}

signed main()
{
    int T=100000;
    // cin>>T;
    srand(time(0));
    while(T--)
    {
        n=rand()%5+2;
        for(int i=1;i<=n;i++) arr[i]=rand()%10;
        if(solve1()!=solve2())
        {
            for(int i=1;i<=n;i++) cout<<arr[i]<<" ";  cout<<'\n';
            cout<<solve1()<<" "<<solve2()<<'\n';
            return 0;
        }
    }
}