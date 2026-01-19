#include<bits/stdc++.h>
using namespace std;
#define int long long
string bit(int x)
{
    string s;
    while(x)
    {
        s+=(x&1)+'0';
        x>>=1;
    }
    reverse(s.begin(),s.end());
    return s;
}

signed main()
{
    int a,b;
    cin>>a>>b;
    string A=bit(a);
    string B=bit(b);
    // for(auto x:A) cout<<x; cout<<'\n';
    // for(auto x:B) cout<<x; cout<<'\n';
    if(A.size()==B.size())
    {
        int t=0;
        int cnt=0;
        while(A[t]==B[t]&&t<A.size())
        {
            if(A[t]=='1') cnt++;
            t++;
        }
        bool jud=0;
        for(int i=t;i<B.size();i++) 
        {
            if(B[i]=='0') 
            {
                jud=1;
                break;
            }
        }
        
        if(jud==0)
        {
            cout<<cnt+B.size()-t;
        }
        else cout<<cnt+B.size()-t-1;
    }
    else
    {   
        int cnt=0;
        for(auto x:B) if(x=='1') cnt++;
        if(cnt==B.size()) cout<<cnt;
        else cout<<B.size()-1;
    }

}