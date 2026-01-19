#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b;
    cin>>n>>b;
    int a[n+1];
    int flag=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==b) a[i]=0,flag=i;
        else if(a[i]<b) a[i]=-1;
        else a[i]=1;
    }
    int ans=0;
    map<int,int>L,R;
    int sum=0;
    for(int i=flag-1;i>=1;i--)
    {
        sum+=a[i];
        L[sum]++;
    }
    sum=0;
    for(int i=flag+1;i<=n;i++)
    {
        sum+=a[i];
        R[sum*-1]++;
    }
    ans+=L[0]+R[0];
    for(auto x:L)
    {
        // if(R.find(x.first)!=R.end())
        // {
            ans+=R[x.first]*L[x.first];
        // }
    }
    cout<<ans+1;
}