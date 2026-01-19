#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string getB(int x,string &s)
{
    string B;
    B.clear();
    int j=1;
    int cnt=0;
    while(j<=2*m&&j<s.size())
    {
        int num=s[j]-'0';
        if(num%x!=0)
        {
            j++;
            if(j>2*m||j>=s.size()) return "";
            num=num*10+s[j]-'0';
        }
        if(num%x!=0||num/x>=10) return "";
        B+=(num/x+'0');
        cnt++;
        if(cnt==m)
        {
            if(j<m) return "";
            else return B;
        } 
        j++;
    }
    return "";
}

string getA(string &B,string &s)
{
    string A;
    int len=B.size();
    int i=1,j=0;
    int tmp=0;
    while(i<s.size())
    {
        tmp=s[i]-'0';
        int b=B[j]-'0';
        if(b==0)
        {
            if(tmp!=0) return "";
        }
        else 
        {
            if(tmp%b!=0)
            {
                i++;
                if(i>=s.size()) return "";
                tmp=tmp*10+s[i]-'0';
                if(tmp%b!=0) return ""; 
            }
            if(tmp/b>=10) return "";
        }
        if(j==0) 
        {
            if(b==0) A+="0";
            else A+=(tmp/b)+'0';
        }
        else 
        {
            if(!A.empty()) 
            {
                if(b!=0) 
                {
                    if(tmp/b+'0' != A.back()) return "";
                }
            }
        }
        i++;
        j++;
        j%=len;
    }
    if(i!=s.size()||j!=0) return "";
    else return A;
}

void solve()
{
    cin>>n>>m;
    string s;
    cin>>s;
    if(s[0]=='0')
    {
        if(s!="0"||(n!=1&&m!=1))
        {
            cout<<"Impossible\n";
            return;
        }
        else 
        {
            if(n==1) 
            {
                cout<<"0"<<" "<<1;
                for(int i=0;i<m-1;i++) cout<<0;
            }
            else 
            {
                cout<<1;
                for(int i=0;i<n-1;i++) cout<<0;
                cout<<" "<<0<<'\n';
            }
            return;
        }
    }
    s="$"+s;
    for(int i=1;i<=9;i++)
    {
        string B=getB(i,s);
        // cout<<B<<" "<<B.size();
        if(B.size()==m&&B!="") 
        {
            string A=getA(B,s);
            if(A!=""&&A.size()==n)
            {
                cout<<A<<" "<<B<<'\n';
                return;
            }
        }
    }
    cout<<"Impossible\n";
}

signed main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}