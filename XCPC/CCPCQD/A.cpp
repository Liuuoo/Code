#include<bits/stdc++.h>
using namespace std;
map<string,int>M;
map<string,pair<int,int>>p;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            string s;
            for(int l=1;l<=k;l++)
            {
                char c;
                cin>>c;
                s+=c;
            }
            M[s]++;
            p[s]={i,j};
        }
    }
    for(auto x:M)
    {
        if(x.second==1)
        {
            cout<<p[x.first].first<<" "<<p[x.first].second;
            break;
        }
    }
}