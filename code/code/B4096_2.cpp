#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n);
    char las='a';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]<las) 
            {
                cout<<"0\n";
                return;
            }
            else las=s[i][j];
        }
    }
    cout<<1<<'\n';
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