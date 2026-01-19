#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
vector<int> arr[N];

map<int,set<int>>M;
map<int,int> cnt;
struct UF
{
    vector<int>fa;
    UF(int n)
    {
        fa.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
    }
    int find(int x)
    {
        if(fa[x]==x) return x;
        else return fa[x]=find(fa[x]);
    }

    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
        {
            return;
        }
        else 
        {
            fa[x]=y;
            return;
        }
    }
};

struct Hash
{
    vector<int>H;
    vector<int>B;
    int base=1e7+7;
    int mod=1e9+7;
    Hash(vector<int>& s)
    {
        H.resize(s.size()+10);
        B.resize(s.size()+10);
        B[0]=1;
        for(int i=1;i<s.size();i++)
        {
            B[i]=B[i-1]*base%mod;
        }
        for(int i=1;i<s.size();i++)
        {
            H[i]=H[i-1]*base%mod+s[i];
            H[i]=H[i]%mod;
        }
    }
    int get(int l,int r)
	{
		return ((H[r]-H[l-1]*B[r-l+1]%mod)%mod+mod)%mod; 
	}
};

signed main()
{
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(0);

    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        cnt[x]++;
    }

    int cnt=1;
    UF uf(n);

    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')')
        {
            vec.pop_back();
        }
        else 
        {
            Hash hs(vec);

            int hsnum=hs.get(1,vec.size()-1);
            // cout<<hsnum<<"\n";

            if(M[hsnum].size()>0)
            {
                uf.merge(cnt,*M[hsnum].begin());
            }

            M[hsnum].insert(cnt);
            vec.push_back(cnt++);
        }
    }
    map<int,set<int>> same;
    for(int i=1;i<=n;i++)
    {
        // cout<<uf.find(i)<<" ";
        same[uf.find(i)].insert(i);
    }

    for(auto x: same)
    {
        
    }
}