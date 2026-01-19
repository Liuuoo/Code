#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dfs(int x,int y,int len)
{
    if(len==1)return 1;
    int ans=0;
    if(x<=len/2&&y<=len/2)
    {
        ans+=dfs(x,y,len/2);
    }
    else if(x<=len/2&&y>len/2)
    {
        ans+=dfs(x,y-len/2,len/2);
        ans+=len/2*len/2;
    }
    else if(x>len/2&&y<=len/2)
    {
        ans+=dfs(x-len/2,y,len/2);
        ans+=len/2*len/2*2;
    }
    else
    {
        ans+=dfs(x-len/2,y-len/2,len/2);
        ans+=len/2*len/2*3;
    }
    return ans;
}
int dfs1(int len,int L,int R)
{
    if(len*len>=L&&len*len>=R)
    {
        return len;
    }
    return dfs1(len*2,L,R);
}
void solve()
{
    int L,R;
    cin>>L>>R;
    int t=dfs1(1,L,R);
}

signed  main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}