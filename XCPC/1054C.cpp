#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;

int main()
{
    int n;
    cin>>n;

    int a[n+1],b[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int ans[n+1];

    for(int i=0;i<n;i++)
    {
        ans[i]=(n-(a[i]+b[i]));
    }
    for(int i=0;i<n;i++)
    {
        int tmp=ans[i];
        int l=0,r=0;
        for(int j=0;j<i;j++)
        {
            if(ans[j]>tmp) l++;
        }
        if(l!=a[i]) 
        {
            cout<<"NO\n";
            return 0;
        }
        for(int j=i+1;j<n;j++)
        {
            if(ans[j]>tmp) r++;
        }
        if(r!=b[i]) 
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
}