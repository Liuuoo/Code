#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string getB(int x,string &s)
{
    string B;
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

string calc(int i,int j)
{
    string A=to_string(i);
    string B=to_string(j);
    string fin;
    for(auto x:A)
    {
        for(auto y:B)
        {
            fin+=to_string((x-'0')*(y-'0'));
        }
    }
    return fin;
}

bool duip(string A,string B,string s)
{
    string ts;
    for(int i=1;i<s.size();i++) ts+=s[i];
    bool flag=false;
    for(int i=pow(10,n-1);i<pow(10,n);i++)
    {
        for(int j=pow(10,m-1);j<pow(10,m);j++)
        {
            if(calc(i,j)==ts)
            {
                if(to_string(i)!=A||to_string(j)!=B)
                {
                    cout<<ts<<" "<<n<<" "<<m<<'\n';
                    cout<<i<<" "<<j<<'\n';
                    cout<<A<<" "<<B<<'\n';
                    return false;
                }
                else 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve()
{
    while(1)
    {
        string s;

        // cin>>n>>m;
        
        // cin>>s;
        // s="$"+s;
        n=rand()%5+1;
        m=rand()%5+1;
        int l=rand()%(2*m*n)+1;
        for(int i=0;i<l;i++) s+=rand()%9+'0'+1;
        cout<<s<<" "<<n<<" "<<m<<'\n';
        s="$"+s;
        vector<pair<int,int>> vec;
        string A,B;
        for(int i=1;i<=9;i++)
        {
            B=getB(i,s);
            if(B!=""&&B.size()==m) 
            {
                A=getA(B,s);
                if(A!=""&&A.size()==n)
                {
                    cout<<A<<" "<<B<<'\n';
                    if(!duip(A,B,s))
                    {
                        return;
                    }
                    // return;
                    break;
                }
            }
        }
        
        // cout<<"Impossible\n";
    }
    
}

signed main() 
{
    srand(time(0));
    int T;
    // cin>>T;
    // while(T--)
    // {
    //     solve();
    // }
    solve();
}
