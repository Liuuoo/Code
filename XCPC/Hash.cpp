#include<bits/stdc++.h>
using namespace std;
struct Hash
{
    const int base=131;
    const int mod=1e9+7;
    string s;
    vector<int>H;
    vector<int>B;
    Hash(string _s)
    {
        s=" "+_s;
        H.resize(s.size());
        B.resize(s.size());
        B[0]=1;
        for(int i=1;i<s.size();i++)
        {
            B[i]=B[i-1]*base%mod;
        }
        for(int i=1;i<s.size();i++)
        {
            H[i]=H[i-1]*base%mod+s[i];
            H[i]%=mod;
        }
    }
    int get(int l, int r)
    {
        l++;
        r++;
        return ((H[r]-H[l-1]*B[r+1-l]%mod)%mod+mod)%mod;
    }
};