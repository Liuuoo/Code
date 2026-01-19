#include<bits/stdc++.h>
using namespace std;

map<int,int> calc(int x)
{
    map<int,int> res;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            res[i]++;
            x/=i;
        }
    }
    if(x>1) res[x]++;
    return res;
}

void solve()
{
    int n;
    cin>>n;
    int p[n],s[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>s[i];
    if(p[0]%s[0]!=0 || s[n-1]%p[n-1]!=0)
    {
        cout<<"NO"<<'\n';
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(p[i]%p[i+1]!=0)
        {
            cout<<"NO"<<'\n';
            return;
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        if(s[i]%s[i-1]!=0)
        {
            cout<<"NO"<<'\n';
            return;
        }
    }
    vector<map<int,int>> miss1(n),miss2(n);
    for(int i=1;i<n;i++)
    {
        miss1[i]=(calc(p[i-1]/p[i]));
    }
    for(int i=n-2;i>=0;i--)
    {
        miss2[i]=(calc(s[i+1]/s[i]));
    }
    for(int i=n-1;i>=0;i--)
    {
        int g=__gcd(s[i],p[i]);
        int b=s[i]*p[i]/g;
        map<int,int>J1=calc(b/p[i]);
        map<int,int>J2=calc(b/s[i]);
        for(auto x:J1)
        {
            if(miss1[i][x.first]!=0)
            {
                cout<<"NO"<<'\n';
                return;
            }
        }
        for(auto x:J2)
        {
            if(miss2[i][x.first]!=0)
            {
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    cout<<"YES"<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}