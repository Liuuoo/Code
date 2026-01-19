#include<bits/stdc++.h>
using namespace std;
string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
    // string s;
string calc(int a,int b)
{
    string ans;
    for(int i=a;i<=b;i++)
    {
        ans+=s[i];
    }
    return ans;
}

bool juddig(string tmp)
{
    for(int i=0;i<tmp.size();i++)
    {
        if(isdigit(tmp[i])) return true;
    }
    return false;
}

bool judchar(string tmp)
{
    for(int i=0;i<tmp.size();i++)
    {
        if(!isdigit(tmp[i])&&!isalpha(tmp[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int i=0,j=s.size()-1;
    int ans=0;
    for(int i=0;i<s.size()-1;i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            string tmp=calc(i,j);
            if(tmp.size()>=8 && tmp.size()<=16)
            {
                if(juddig(tmp)&&judchar(tmp))
                {
                    // cout<<tmp<<"\n";
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}