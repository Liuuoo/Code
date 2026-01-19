#include<bits/stdc++.h>
using namespace std;
vector<pair<char,int>> vec;
int nn,k;

set<string> ans;

void dfs1(int n,string s)
{
    if(n==k)
    {
        ans.insert(s);
        // cout<<s<<'\n';
        return;
    }
    for(int j=0;j<2;j++)
    {
        string tmp=s;
        int p=(vec[n].second)-1;
        if(j==0) tmp[p]='W';
        else tmp[p]='B';
        dfs1(n+1,tmp);
    }
}

int dfs(int n,string s,char play)
{
    
}

int main()
{
    cin>>nn>>k;
    string ss; cin>>ss;
    for(int i=0;i<k;i++)
    {
        char c; int p;
        cin>>c>>p;
        vec.push_back({c,p});
        cout<<vec[i].second<<'\n';
    }
    dfs1(0,ss);
    for(int i=0;i<k;i++)
    {
        
    }
}