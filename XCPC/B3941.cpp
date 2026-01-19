#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1234];

signed main()
{
    cin>>n;
    int m=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {   
        a[i]=(a[i]*a[i-1]/(__gcd(a[i],a[i-1])));
    }
    cout<<a[n-1];
}