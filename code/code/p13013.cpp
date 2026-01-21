#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,b;

bool check1(int x)
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

// bool check(int x)
// {
//     for(int i=0;i<=x;i++)
//     {
//         int z=i;
//         int f=x-i;
//         if(a*z+b*f<=n&&b*z+a*f<=m) return true;
//     }
//     return false;
// }

signed main() 
{
    // srand(time(0));
    // while(1)
    // {
        cin>>n>>m>>a>>b;
        // n=rand()%2000, m=rand()%2000,a=rand()%1000,b=rand()%1000;
        // n++,m++,a++,b++;
        if(a<b)
        {
            swap(a,b);
            swap(n,m);
        }
        int l=0, r=min(n,m);
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check1(mid)) l=mid+1;
            else r=mid-1;
        }
        // int L=0, R=min(n,m);
        // while(L<=R)
        // {
        //     int mid=(L+R)>>1;
        //     if(check(mid)) L=mid+1;
        //     else R=mid-1;
        // }
        if(!check1(r)) r--;
        if(a==b) r=min(n,m)/a;
        cout<<r;
        // cout<<r<<" "<<R<<'\n';
        // if(r!=R)
        // {
        //     cout<<n<<" "<<m<<'\n';
        //     cout<<a<<" "<<b<<'\n';
        //     cout<<r<<" "<<R;
        //     break;
        // }
    // }
    
}
/*
830 1079
357 18
5 4
*/