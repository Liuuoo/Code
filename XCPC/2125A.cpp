#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    bool flag=false;
    if(s.size()<3)
    {
        cout<<s<<'\n';
        return;
    }
    for(int i=0;i<=s.size()-3;i++)
    {
        if(s[i]=='F'&&s[i+1]=='F'&&s[i+2]=='T')
        {
            flag=true;
        }
        if(s[i]=='N'&&s[i+1]=='T'&&s[i+2]=='T')
        {
            flag=true;
        }
    }
    if(!flag) cout<<s<<'\n';
    else 
    {
        sort(s.begin(),s.end(),greater<char>());
        cout<<s<<'\n';
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