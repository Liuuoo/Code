#include<bits/stdc++.h>
using namespace std;

int find(string s)
{
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        int j=i;
        int cnt=0;
        string tmp;
        while(j<s.size()&&cnt<7)
        {
            tmp+=s[j];
            j++;
            cnt++;
        }
        // cout<<tmp<<"\n";
        if(tmp=="nanjing")
        {
            res++;
        }
    }
    return res;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ns=s+s;
    if(s.size()<7)
    {
        cout<<"0\n";
        return;
    }
    int res=0;
    for(int i=0;i<=min(k,6);i++)
    {
        string tmp;
        int j=i;
        int cnt=0;
        while(cnt<n)
        {
            tmp+=ns[j];
            j++;
            cnt++;
        }
        // cout<<tmp<<'\n';
        res=max(res,find(tmp));
    }
    cout<<res<<'\n';
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