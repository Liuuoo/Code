#include<bits/stdc++.h>
using namespace std;
#define int long long

string to_bit(int n)
{
    string res;
    while(n)
    {
        res+=(n&1)+'0';
        n>>=1;
    }
    while(res.size()%7!=0) res+='0';
    return res;
}

int to_10(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans+=(s[i]-'0')*pow(2,i);
    }
    return ans;
}

string to_16(int x)
{
    string res;
    while(x)
    {
        int tmp=x%16;
        if(tmp<10) res+=tmp+'0';
        else res+=tmp-10+'A';
        x/=16;
    }
    while(res.size()<2) res+='0';
    reverse(res.begin(),res.end());
    return res;
}

signed main()
{
    int n;
    cin>>n;
    if(n==0) 
    {
        cout<<"00";
    }
    else 
    {
        string s=to_bit(n);
        for(int i=0;i<s.size();i++)
        {
            int j=i;
            int cnt=0;
            string tmp;
            while(cnt<7)
            {
                tmp+=s[j++];
                cnt++;
            }
            i=j-1;
            if(j==s.size()) tmp+='0';
            else tmp+='1';
            // cout<<tmp<<' ';
            cout<<to_16(to_10(tmp))<<" ";
        }
    }
}