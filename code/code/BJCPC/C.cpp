#include<bits/stdc++.h>
using namespace std;

string to_bit(int x)
{
    string res;
    while(x)
    {
        res+=(x&1)+'0';
        x/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    string bit=to_bit(n);
    cout<<bit<<endl;
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