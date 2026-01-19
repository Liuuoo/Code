#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=-1;
    int x=a[n-1];
    for(int j=0;j<n-1;j++)
    {
        if(a[j]<=x)
        {
            swap(a[++i],a[j]);
        }
    }
    swap(a[++i],a[n-1]);
    for(int x=0;x<n;x++)
    {
        if(x>0) cout<<' ';
        if(x==i) cout<<'['<<a[x]<<']';
        else cout<<a[x];
    }
    cout<<endl;
}