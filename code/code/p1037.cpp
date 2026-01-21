#include<bits/stdc++.h>
using namespace std;
const int N=20;
string nn;
int k;
int len;
vector<pair<int,int>> vec;
set<string> ans;
void dfs(string s)
{
    // cout<<s<<'\n';
    ans.insert(s);
    for(int j=0;j<len;j++)
    {
        string tmp=s;
        int l=0,r=k;
        int cnt=0;
        while(l<r)
        {
            // cout<<l<<" "<<r<<'\n';
            int m=(l+r)>>1;
            if(vec[m].first>=tmp[j]-'0') r=m;
            else l=m+1;
        }
        // cout<<l<<"\n";
        if(vec[l].first==tmp[j]-'0')
        {
            tmp[j]=vec[l].second+'0';
            // cout<<tmp<<'\n';
            dfs(tmp);
        }
    }
}

int main()
{
    cin>>nn>>k;
    len=nn.size();
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x!=y) vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end());
    // for(auto x:vec)
    // {
    //     cout<<x.first<<" "<<x.second<<'\n';
    // }
    dfs(nn);
    cout<<ans.size();
}