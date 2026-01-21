#include<bits/stdc++.h>
using namespace std;
#define int long long

bool jud(string s)
{
    if(s.size()<8||s.size()>16) return false;
    bool jud1=false;
    bool jud2=false;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) jud1=true;
        if(!isalpha(s[i])&&!isdigit(s[i])) jud2=true;
    }
    if(jud1&&jud2) return true;
    else return false;
}

signed main()
{
    int ans=0;
    // string s="+-*/0601";
    string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            string tmp;
            for(int k=i;k<=j;k++)
            {
                tmp+=s[k];
            }
            // cout<<tmp<<"\n";
            if(jud(tmp)) 
            {
                ans++;  
                cout<<tmp<<"\n";
            }
        }
    }
    cout<<ans;
}