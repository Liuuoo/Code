#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m;
int a[N],b[N];
bool check(double x)
{
    for(int i=0;i<n-1;i++)
    {
        x-=((m+x)*1.0/a[i]);
        if(x<=0) return false;
        x-=((m+x)*1.0/b[i+1]);
        if(x<=0) return false;
    }
    x-=((m+x)*1.0/a[n-1]);
    if(x<=0) return false;
    x-=((m+x)*1.0/b[0]);
    return (x>=0);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    
    double l=0, r=1e9+10;
    for(int i=0;i<30000;i++)
    {
        double m=(l+r)/2;
        if(check(m)) r=m;
        else l=m;
        if(l==r) break;
    }
    if(l>1e9+1) l=-1;
    printf("%.7lf",l);
}
