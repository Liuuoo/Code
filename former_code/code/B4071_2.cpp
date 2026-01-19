#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

int jud(int fin,vector<multiset<int>> vec)
{
    int ans=0;
    int ini=vec[1].size();
    for(int i=2;i<=n;i++)
    {
        int nd=(int)vec[i].size()-(fin-1);
        for(int j=0;j<nd;j++)
        {
            ans+=*vec[i].begin();
            vec[i].erase(vec[i].begin());
            ini++;
        }
    }
    if(ini>=fin) return ans;
    else 
    {
        int nd=fin-ini;
        multiset<int> tmp;
        for(int i=2;i<=n;i++)
        {
            for(auto x:vec[i]) tmp.insert(x);
        }
        for(int i=0;i<nd;i++)
        {
            ans+=*tmp.begin();
            tmp.erase(tmp.begin());
        }
        return ans;
    }
    
}

int solve1(vector<multiset<int>> vec)
{
    int ans=INT_MAX;
    for(int i=max((int)vec[1].size(),1ll);i<=m;i++)
    {
        ans=min(ans,jud(i,vec));
    }
    return ans;
}

signed main()
{
    srand(time(0));
    while(1)
    {
        n=rand()%10;
        m=rand()%10;
        vector<multiset<int>> vec(n+1);
        for(int i=0;i<m;i++)
        {
            int p,c;
            cin>>p>>c;
            vec[p].insert(c);
        }
        int ans1=solve1(vec);
        
    }

}