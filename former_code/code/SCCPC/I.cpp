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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

    string s[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    map<pair<int,int>,bool>M;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        Hash hs(s[i]);
        for(int j=0;j<s[i].size();j++)
        {
            pair<int,int> num=hs.get(j,s[i].size()-1);
            if(M[num]==false)
            {
                M[num]=true;
                ans++;
            }
        }
    }
    cout<<ans;
}
/*
3
fbudpefs 
cfhjoofs
edpouftu
*/