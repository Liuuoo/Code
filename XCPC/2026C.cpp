#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    string s;
    cin>>s;
    s="$"+s;
    vector<int>vec0;
    vector<int>vec1;
    for(int i=1;i<=n;i++)
    {
        int x=s[i]-'0';
        if(x==0) 
        {
            vec0.push_back(i);
            ans+=i;
        }
        else vec1.push_back(i);
    }
    while(vec0.size()>=1&&vec1.size()>=1)
    {
        int t1=vec1.back();
        int t0=vec0.back();
        if(t1>t0)
        {
            vec1.pop_back();
            vec0.pop_back();
        }
        else 
        {
            vec0.pop_back();
        }
    }
    for(int i=0;i<(vec1.size()+1)/2;i++)
    {
        ans+=vec1[i];
    }
    cout<<ans<<"\n";
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