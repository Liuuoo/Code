#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    set<string> A,B,all;
    for(int i=1;i<=n;i++) 
    {
        string s;
        cin>>s;
        for(auto &x:s) x=tolower(x);
        A.insert(s);
        all.insert(s);
    }
    for(int i=1;i<=m;i++) 
    {
        string s;
        cin>>s;
        for(auto &x:s) x=tolower(x);
        B.insert(s);
        all.insert(s);
    }
    set<string> sm;
    for(auto x:A)
    {
        if(B.find(x)!=B.end())
        {
            sm.insert(x);
        }
    }
    cout<<sm.size()<<"\n"<<all.size();
}