#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0,ans=0;

    while(i<n&&j<m)
    {
        while(j<m&&b[j]<a[i]) j++;
        if(j>=m) break;
        ans+=b[j];
        j++;
        i++;
    }
    if(i!=n) cout<<"you died!";
    else cout<<ans;
}