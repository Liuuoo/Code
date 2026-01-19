#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s[0]<<"\n";
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