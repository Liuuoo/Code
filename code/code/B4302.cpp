#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() 
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        int x;
        cin>>x;
        ans=(ans^x);
    }
    cout<<ans;
}