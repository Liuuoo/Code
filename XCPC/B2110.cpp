#include<bits/stdc++.h>
using namespace std;
int cnt[500];
int main()
{
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        cnt[s[i]]++;
    }
    bool flag=false;
    for(auto x:s)
    {
        if(cnt[x]==1) 
        {
            cout<<x;
            flag=true;
            break;
        }
    }
    if(!flag) cout<<"no";
}