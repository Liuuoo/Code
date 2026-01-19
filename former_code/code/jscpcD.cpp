#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans+=pow(2,i)*(s[i]-'0');
    }
    cout<<ans<<'\n';
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