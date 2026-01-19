#include<bits/stdc++.h>
using namespace std;

int calc(int x)
{
    int cnt=0;
    while(x)
    {
        x/=10;
        cnt++;
    }
    return cnt;
}

void solve()
{
    int m;
    cin>>m;
    int mm=m;
    int n=calc(m);
    int sum=0;
    while(m)
    {
        int tmp=m%10;
        m/=10;
        sum+=pow(tmp,n);
    }
    if(sum==mm) cout<<"T\n";
    else cout<<"F\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
   
}