#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    int ans=0;
    for(int i=0;i<min(n,33);i++)
    {
        for(int j=0;j<min(n,33);j++)
        {
            if(i!=j) ans=max(ans,(a[i]&a[j]));
        }
    }
    cout<<ans;
}