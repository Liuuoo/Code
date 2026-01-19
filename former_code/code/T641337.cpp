#include<bits/stdc++.h>
using namespace std;
#define int long long

int to_int(string s)
{
    // reverse(s.begin(),s.end());
    int res=0;
    int t=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        res+=(s[i]-'0')*pow(2,t++);
    }
    return res;
}

string to_string(int n,int all)
{
    string res;
    while(n)
    {
        res+=(n%2)+'0';
        n/=2;
    }
    while(res.size()!=all) res+='0';
    // reverse(res.begin(),res.end());
    return res;
}

int calc(string s)
{
    int res=0;
    for(auto x:s)
    {
        if(x=='1') res++;
    }
    return res;
}

bool jud(string s,int k,int m)
{
    string p,n;
    for(int i=s.size()-1;i>s.size()-1-k;i--) p+=s[i];
    for(int i=s.size()-1-k;i>=0;i--)
    {
        n+=s[i];
        if((i)%k==0)
        {
            int res=calc(p)+calc(n);
            if(res>m) return false;
            p=n;
            n="";
        }
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false); // 关闭同步
    cin.tie(nullptr); // 解绑 cin 和 cout
    cout.tie(nullptr); // 解绑 cout 和其他流
    string l;
    cin>>l;
    int k,m;
    cin>>k>>m;
    string res;
    for(int i=0;i<k;i++) res+=l;
    // cout<<res<<'\n';
    int n=to_int(res);
    // cout<<n<<'\n';
    int all=res.size();
    int ans=0;
    
    for(int i=0;i<=n;i++)
    {
        string tmp=to_string(i,all);
        if(jud(tmp,l.size(),m)) 
        {
            // cout<<tmp<<'\n';
            ans++;
        }
    }
    cout<<ans;
}