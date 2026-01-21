#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    s="$"+s;
    vector<int> c(3);
    for(int i=2;i<s.size();i+=2)
    {
        if(s[i]=='2') continue;
        else 
        {
            s[i]=s[i]=='1'?'0':'1';
        }
    }
    for(int i=1;i<s.size();i++) c[s[i]-'0']++;
    int delt=abs(c[0]-c[1]);
    if(c[2]<=delt)
    {
        cout<<delt-c[2]<<'\n';
    }
    else 
    {
        cout<<((c[2]-delt)%2)<<'\n';
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