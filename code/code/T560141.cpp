#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int m;
    cin>>m;
    int min=ceil((1.0+sqrt(1+8*m))/2.0);
    if(min>m) cout<<"Lose!\n";
    else 
    {
        cout<<min<<" "<<(m-3)*2+4<<'\n';
    }
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}