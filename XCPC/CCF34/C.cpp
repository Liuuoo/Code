#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string s;
    int c;
};
bool cmp(Node &i,Node &j)
{
    if(i.c!=j.c) return i.s<j.s;
    else return i.c>j.c;
}
int main()
{
    int n,m;
    cin>>n>>m;

    map<string,int> M;
    map<string,int> C;
    vector<string>vec(n+1);
    int mx=0;
    vector<string>ans;
    for(int i=1;i<=n;i++)
    {
        string s; int x;
        cin>>s>>x;
        mx=max(mx,(int)s.size());
        M[s]+=x;
        vec[i]=s;
        for(auto x:s) 
        {string t; t+=x;
            ans.push_back(t);
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    // assert(mx<100);
    for(int i=2;i<=mx;i++)
    {
        for(int j=1;j<=n;j++)
        {
            map<string,int> tc;
            string nx=vec[j];
            if(nx.size()<i) continue;
            for(int k=0;k<nx.size();k++)
            {
                int cnt=0;
                string tmp;
                for(int l=k;cnt<i&&(l+i)<=nx.size();l++)
                {
                    tmp+=nx[l];
                    cnt++;
                }
                if(tmp.size()==i) tc[tmp]++;
            }
            for(auto x:tc)
            {
                C[x.first]+=M[vec[j]]*x.second;
            }
        }

    }
    vector<Node> ans2;
    for(auto x:C)
    {
        ans2.push_back({x.first,x.second});
    }
    sort(ans2.begin(),ans2.end(),cmp);

    for(auto x:ans) cout<<x<<'\n';
    for(auto x: ans2)
    {
        cout<<x.s<<'\n';
    }
}
