#include<bits/stdc++.h>
using namespace std;

string to_bit(long long n)
{
    string s;
    while(n)
    {
        s+=(n%2)+'0';
        n/=2;
    }
    while(s.size()%7!=0) s+='0';

    return s;
}

int to_10(string ss)
{
    int ans=0;
    for(int i=0;i<ss.size();i++)
    {
        ans+=(ss[i]-'0')*pow(2,i);
    }
    return ans;
}

string to_16(long long num)
{
    string ans;
    while(num)
    {
        if(num%16>=10) ans+=(num%16)-10+'A';
        else ans+=(num%16)+'0';
        num/=16;
    }
    if(ans.size()<2) ans+='0';
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    string bit_s=to_bit(n);
    cout<<bit_s<<" ";
    for(int i=0;i<bit_s.size();i+=7)
    {
        int j=i;
        int cnt=0;
        string tmp;

        while(cnt<7)
        {
            tmp+=bit_s[j++];
            cnt++;
        }
        if(i<=bit_s.size()-14) tmp+='1';
        else tmp+='0';
        // cout<<tmp<<" ";
        cout<<to_16(to_10(tmp))<<" ";
    }
    if(n==0) cout<<"00";
}