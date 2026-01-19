#include<bits/stdc++.h>
using  namespace std;

bool cmp(string s1, string s2)
{
    int ln=min(s1.size(),s2.size());
    for(int i=0;i<ln;i++)
    {
        if(s1[i]!=s2[i]) return s1[i]<s2[i];
    }
    return s1>s2;
}

int main()
{
    int n;
    cin>>n;
    string s[n+1];
    for(int i=0;i<n;i++)
    {
        int n;
        cin>>n;
        s[i]=to_string(n);
    }
    sort(s,s+n,cmp);
    for(int i=n-1;i>=0;i--) cout<<s[i];
}