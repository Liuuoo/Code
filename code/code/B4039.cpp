#include<bits/stdc++.h>
using namespace std;

string sub(string s,int l,int r)
{
    string tmp;
    for(int i=l;i<=r;i++)
    {
        tmp+=s[i];
    }
    return tmp;
}

bool check(string s)
{
    if(s.size()<2) return false;
    string tmp=s;
    reverse(tmp.begin(),tmp.end());
    return (tmp==s);
}

void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        string l=sub(s,0,i);
        string r=sub(s,i+1,s.size()-1);
        if(check(l)&&check(r))
        {
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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