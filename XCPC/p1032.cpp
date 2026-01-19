#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Hash
{
    vector<int> B,H;
    const int mod=1e9+7;
    const int base=131;
    string s;
    Hash(string &_s)
    {
        s="$"+_s;
        B.resize(s.size()+10);
        H.resize(s.size()+10);
        B[0]=1;
        for(int i=1;i<s.size();i++) B[i]=B[i-1]*base%mod;
        for(int i=1;i<s.size();i++)
        {
            H[i]=H[i-1]*base%mod+s[i];
            H[i]%=mod;
        }
    }
    int get(int l,int r)
    {
        l++;
        r++;
        return ((H[r]-H[l-1]*B[r-l+1]%mod)%mod+mod)%mod; 
    }
};

string change(string &s,int l,int r,string &tag)
{
    string res;
    for(int i=0;i<l;i++) res+=s[i];
    res+=tag;
    for(int i=r+1;i<s.size();i++) res+=s[i];
    return res;
}

signed main()
{
    string s1,s2;
    int n=10;
    cin>>s1>>s2;
    string a,b;
    map<int,vector<string>>M;
    map<int,vector<string>>M2;
    map<string,int>step;
    map<string,int>step2;
    while(cin>>a>>b)
    {
        
        Hash hs(a);
        int num=hs.get(0,a.size()-1);
        M[num].push_back(b);
        Hash hs2(b);
        int num2=hs2.get(0,b.size()-1);
        M2[num2].push_back(a);
    }
    queue<string>q;
    q.push(s1);
    step[s1]=0;
    while(!q.empty())
    {
        string f=q.front();
        if(step[f]==5) break;
        Hash hs(f);
        q.pop();
        for(int i=0;i<f.size();i++)
        {
            for(int j=i;j<f.size();j++)
            {
                int num=hs.get(i,j);
                if(M[num].size()!=0)
                {
                    for(auto x:M[num])
                    {
                        string tmp=change(f,i,j,x);
                        q.push(tmp);
                        step[tmp]=step[f]+1;
                    }
                }
            }
        }
    }
    if(step[s2]!=0) 
    {
        cout<<step[s2];
    }
    else 
    {
        queue<string>q2;
        q2.push(s2);
        step2[s2]=0;
        while(!q2.empty())
        {
            string f=q2.front();
            if(step2[f]==5) break;
            Hash hs(f);
            q2.pop();
            for(int i=0;i<f.size();i++)
            {
                for(int j=i;j<=f.size();j++)
                {
                    int num2=hs.get(i,j);
                    if(M2[num2].size()!=0)
                    {
                        for(auto x:M2[num2])
                        {
                            string tmp=change(f,i,j,x);
                            q2.push(tmp);
                            if(step[tmp]!=0)
                            {
                                cout<<step[tmp]+step2[f]+1;
                                return 0;
                            }
                            step2[tmp]=step2[f]+1;
                        }
                    }
                }
            }
        }
        cout<<"NO ANSWER!";
    }
}