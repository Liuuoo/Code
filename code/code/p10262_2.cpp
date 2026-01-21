#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
bool vis[N];
signed main()
{
    int ans=0;
    int f=0;
    int p=0;
    string s;
    cin>>p>>s;
    s="$"+s;
    int tmp=0;
    vis[0]=true;
    for(int i=1;i<s.size();i++)
    {
        if(vis[i-1]==true) f++;
        tmp=(tmp*10+s[i]-'0')%p;
        if(tmp==0)
        {   
            if(!vis[i-1]) f++;
            vis[i]=true;
            ans+=f;
        }
    }
    cout<<ans;
}