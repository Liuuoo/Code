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
    map<pair<int,int>,int> M;
    while(n--)
    {
        string s;
        cin>>s;
        vec.push_back(s);
        Hash hs(s);
        M[hs.get(0,s.size()-1)]++;
    }
    int ans=0;
    for(auto x:vec)
    {
        set<string>vis;
        for(int i=0;i<x.size();i++)
        {
            for(int j=i;j<x.size();j++)
            {
                string tmp;
                for(int k=i;k<=j;k++)
                {
                    tmp+=x[k];
                }
                Hash hs(tmp);
                auto num=hs.get(0,tmp.size()-1);
                if(vis.find(tmp)==vis.end())
                {
                    vis.insert(tmp);

                    if(tmp==x)
                    {
                        ans+=M[num]-1;
                    }
                    else 
                    {
                        ans+=M[num];
                    }
                }
            }
        }
    }
    cout<<ans;
}