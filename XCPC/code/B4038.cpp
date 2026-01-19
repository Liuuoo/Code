#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int minn=INT_MAX;
    int maxx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<k) cout<<minn<<" ";
        else if(a[i]>k) cout<<maxx<<" ";
        else cout<<a[i]<<" ";
    }
}