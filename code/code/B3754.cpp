#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    cin>>x>>y;

    // 设abc 鸡猫兔
    // a+b+c=x; ->2a+2b+2c=2x
    // 2a+3b+4c=y
    // b-2c=y-2x
    // 2c=y-2x-b
    // c=(y-2x-b)/2
    // b-[0,x]
    // 所以c[(y-3x)/2,(y-2x)/2]
    cout<<max(0,(y-3*x))<<" "<<max(0,(y-2*x)/2)<<'\n';
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