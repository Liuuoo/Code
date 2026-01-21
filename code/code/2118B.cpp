#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    cout<<2*n-1<<'\n';
    cout<<1<<" "<<1<<" "<<n<<'\n';
    for(int i=2;i<=n;i++)
    {
        cout<<i<<" "<<1<<" "<<i-1<<"\n";
        cout<<i<<" "<<i<<' '<<n<<'\n';
    }
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