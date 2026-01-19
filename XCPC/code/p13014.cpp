#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() 
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    set<int>S;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        S.insert(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int g=*S.begin()+i;
        for(auto x:S)
        {
            g=__gcd(g,x+i);
        }
        cout<<g<<'\n';
    }
}