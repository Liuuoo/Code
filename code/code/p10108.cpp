#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    vector<int> b(n);
    vector<int> pri(n,INT_MIN);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    pri[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i-a[j]>=0&&pri[i-a[j]]!=INT_MIN)
            {
                pri[i]=max(pri[i],pri[i-a[j]]+b[i-a[j]]);
            }
        }
    }
    int ans=INT64_MIN;
    for(int i=0;i<n;i++)
    {
        bool jud=false;
        for(int j=0;j<m;j++)
        {
            if(pri[i]!=INT_MIN && i+a[j]>=n)
            {
                jud=true;
            } 
        }
        if(jud) ans=max(ans,pri[i]+b[i]);
    }
    cout<<ans;
}