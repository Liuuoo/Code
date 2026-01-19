#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];

int mgcd(int l,int r)
{
    int ans=a[l];
    for(int i=l;i<=r;i++)
    {
        ans=__gcd(ans,a[i]);
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>a[i];

    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<mgcd(l,r)<<'\n';;
    }
}