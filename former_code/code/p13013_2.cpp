#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,b;

bool check(int x)
{
    double A=(n-b*x)*1.0/(a-b);
    if(A<0) return false;

    double B=(a*x-m)*1.0/(a-b);
    if(B>(double)x) return false;

    if(B>A) return false;
    else 
    {
        int ans=B;
        if(ans<B) ans++;
        return (ans<=A);
    }
}

signed main() 
{
    cin>>n>>m>>a>>b;
    if(a<b) 
    {
        swap(a,b);
        swap(n,m);
    }
    int l=0, r=min(n,m);
    while(l<=r)
    {
        cout<<l<<" "<<r<<"\n";
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    if(!check(r)) r--;
    if(a==b) r=min(n,m)/a;
    cout<<r;
}