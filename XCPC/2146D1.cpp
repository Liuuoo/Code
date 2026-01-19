#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> to_bit(int x)
{
    vector<int> res;
    while(x)
    {
        res.push_back(x%2);
        x/=2;
    }
    return res; //注意这边未反转
}

int re(vector<int> vec)
{
    int res=0;
    int t=0;
    for(auto x:vec)
    {
        res+=x*pow(2,t);
        t++;
    }
    return res;
}

void solve()
{
    int l,r;
    cin>>l>>r;
    map<int,bool>vis;
    vector<int> ans(r+1);
    for(int i=r;i>=0;i--)
    {
        if(vis[i]) continue;
        else
        {
            vis[i]=true;
            vector<int> I=to_bit(i);
            vector<int> tmp;
            for(auto x:I)
            {
                int val;
                if(x==1) val=0;
                else val=1;
                tmp.push_back(val);
            }
            int num=re(tmp);
            ans[i]=num;
            ans[num]=i;
            vis[num]=true;
        }
    }
    int c=0;
    for(int i=0;i<=r;i++)
    {
        c+=(ans[i]|i);
        // cout<<ans[i]<<" ";
    }
    cout<<c<<'\n';
    for(int i=0;i<=r;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
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