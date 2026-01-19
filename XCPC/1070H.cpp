#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Hash
{
    const int base=250343;
    const int mod=1e9+7;

    const int base2=212141;
    const int mod2=1e7+9;

    vector<int>H;
    vector<int>B;
    vector<int>H2;
    vector<int>B2;
    string s;
    Hash(string _s)
    {
        s="$"+_s;
        H.resize(s.size()+10);
        B.resize(s.size()+10);

        H2.resize(s.size()+10);
        B2.resize(s.size()+10);

        B[0]=1;
        B2[0]=1;

        for(int i=1;i<s.size();i++)
        {
            B[i]=B[i-1]*base%mod;
            B[i]%=mod;

            B2[i]=B2[i-1]*base2%mod2;
            B2[i]%=mod2;

        }
        for(int i=1;i<s.size();i++)
        {
            H[i]=(H[i-1]*base)%mod+s[i];
            H[i]%=mod;

            H2[i]=(H2[i-1]*base2)%mod2+s[i];
            H2[i]%=mod2;
        }
    }
    pair<int,int> get(int l,int r)
    {
        l++;
        r++;
        int hs1=(((H[r]-H[l-1]*B[r-l+1])%mod+mod)%mod)%mod;
        int hs2=(((H2[r]-H2[l-1]*B2[r-l+1])%mod2+mod2)%mod2)%mod2;
        return {hs1,hs2};
    }
};

signed main()
{
    int n;
    cin>>n;
    vector<string>vec;
    while(n--)
    {
        string s;
        cin>>s;
        vec.push_back(s);
    }
    vector<string>q;
    int m;
    cin>>m;
    map<pair<int,int>,int> cnt;
    map<pair<int,int>,string> ans;
    while(m--)
    {
        string s;
        cin>>s;
        q.push_back(s);
        Hash hs(s);
        auto num=hs.get(0,s.size()-1);
        cnt[num]=0;
        ans[num]="-";
    }
    for(auto x:vec)
    {
        Hash hs(x);
        set<pair<int,int>> vis;
        for(int i=0;i<x.size();i++)
        {
            for(int j=i;j<x.size();j++)
            {
                auto num=hs.get(i,j);
                if(cnt.count(num)&&vis.find(num)==vis.end())
                {
                    cnt[num]++;
                    ans[num]=x;
                    vis.insert(num);
                }
            }
        }
    }
    for(auto x:q)
    {
        Hash hs(x);
        auto num=hs.get(0,x.size()-1);
        cout<<cnt[num]<<" "<<ans[num]<<"\n";
    }
}