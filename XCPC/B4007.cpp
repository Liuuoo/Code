#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a;
    cin>>a;
    int b=sqrt(sqrt(a));
    if(b*b*b*b==a) cout<<b<<'\n';
    else cout<<"-1\n";
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