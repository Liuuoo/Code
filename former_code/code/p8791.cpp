#include<bits/stdc++.h>
using namespace std;
#define int long long
int calc1(string s)
{
    int cnt=0;
    for(auto x:s) if(x=='=') cnt++;
    return cnt;
}

int calc2(string s,char c1,char c2,bool change)
{
    int i=0,j=0;
    int cnt=0;
    while(i<s.size())
    {
        if(s[i]==c1)
        {
            j=i+1;
            string tmp="";
            while(s[j]!=c2)
            {
                tmp+=s[j];
                j++;
            }
            if(change) cnt+=stoi(tmp);
            else cnt+=tmp.size();
            i=j;
        }
        i++;
    }
    return cnt;
}


signed main() 
{
    int T;
    cin>>T;
    int ans=0;
    map<string,int> M;
    M["int"]=4;
    M["long"]=8;
    while(T--)
    {
        string type,s;
        cin>>type;
        getline(cin,s);
        while(s.back()=='\n'||s.back()=='\r') s.pop_back();
        if(M[type]!=0)
        {
            ans+=M[type]*calc1(s);
        }
        else if(type=="String")
        {
            ans+=calc2(s,'"','"',0);
        }
        else 
        {
            string nt;
            for(int i=0;i<type.size()-2;i++) nt+=type[i];
            ans+=M[nt]*calc2(s,'[',']',1);
        }
    }    
    int G=0,MB=0,K=0,B=0;
    B=ans%1024;
    K=ans/1024%1024;
    MB=ans/1024/1024%1024;
    G=ans/1024/1024/1024;
    if(G!=0) cout<<G<<"GB";
    if(MB!=0) cout<<MB<<"MB";
    if(K!=0) cout<<K<<"KB";
    if(B!=0) cout<<B<<"B";
} 
