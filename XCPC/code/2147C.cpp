#include<bits/stdc++.h>
using namespace std;

bool jud(string &s)
{
    int i=0;
    while(i<s.size())
    {
        int j=i;
        bool flag=false;
        int cnt=0;
        while(j<s.size()&&s[j]!='2')
        {
            if(s[j]=='0')
            {
                if(j==0||j==s.size()-1)
                {
                    flag=true;
                }
                if(j+1<s.size()&&s[j+1]=='0')
                {
                    flag=true;
                }
                cnt++;
            }   
            j++;
        }
        if(!flag&&cnt%2) return false;
        i=j+1;
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;
    vector<char> vec(n+1);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        vec[i]=c;
    }
    string s;
    int i=1;
    while(i<=n)
    {
        int j=i;
        int cnt0=0,cnt1=0;
        while(j<=n&&vec[j]==vec[i])
        {
            j++;
            if(vec[i]=='1') cnt1++;
            else cnt0++;
        }
        if(cnt0==0)
        {
            if(cnt1>1)
            {
                s+="2";
            }
            else s+='1';
        }
        else 
        {
            if(cnt0>1)
            {
                s+="00";
            }
            else s+='0';
        }
        i=j;
    }
    if(jud(s)) cout<<"YES\n";
    else cout<<"NO\n";
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