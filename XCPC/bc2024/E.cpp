#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    sort(s2.begin(),s2.end());
    int i=0,j=0;
    string ans;
    while(1)
    {
        if(s2[j]<s1[i])
        {
            ans+=s2[j];
            j++;
        }
        else 
        {
            ans+=s1[i];
            i++;
        }
        if(i==s1.size()||j==s2.size()) break;
    }
    while(i!=s1.size()) 
    {
        ans+=s1[i];
        i++;
    }
    while(j!=s2.size()) 
    {
        ans+=s2[j];
        j++;
    }
    cout<<ans;
}