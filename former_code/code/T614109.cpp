#include<bits/stdc++.h>
using namespace std;
#define int long long
int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
signed main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0;
    int ans=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            cnt++;
        }
        else ans++;
    }
    if(k+1>s.size()) cout<<"0";
    else 
    {
        int maxd=min(cnt,k);
        int mind=max(k-ans,0ll);
        cout<<maxd-mind+1;
    }
}