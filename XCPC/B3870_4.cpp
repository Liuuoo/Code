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
    string s=to_bit(n);
    // cout<<s;
    int i=0,cnt=0;
    while(i<s.size())
    {
        string tmp;
        while(cnt<7)
        {
            tmp+=s[i];
            i++;
            cnt++;
        } 
        if(i==s.size()) tmp+='0'; // 课上这边写反了，写成tmp+='1'了，导致运行错误
        else tmp+='1';
        cout<<to_16(to_10(tmp))<<" ";
        tmp="";
        cnt=0;
    }
    if(n==0) cout<<"00"; // 0的时候上面不会输出，补上一个
}