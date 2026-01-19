#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    string s;
    cin>>s;
    int num=0;
    for(auto x:s)
    {
        if(isupper(x))
        {
            num+=(x*-1);
        }
        else num+=(x-'a'+1);
    }
    cout<<num<<'\n';
}

int main()
{
    int T=1;
    while(T--)
    {
        solve();
    }
}