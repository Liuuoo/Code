#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m;
    cin>>n>>m;
    int c[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    sort(c,c+n);
    for(int j=0;j<m;j++)
    {
        int x;
        cin>>x;
        if(x>0) c[n-1]+=x;
        else c[0]+=x;
    }
    cout<<c[n-1];
}