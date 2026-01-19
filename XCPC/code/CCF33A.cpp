#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n+1);
    for(int i=1;i<=n;i++)
    {
        int k; cin>>k;
        vec[i].resize(k+1);
        for(int j=1;j<=k;j++) cin>>vec[i][j];
    }
    for(int i=1;i<=m;i++)
    {
        int t=0,all=0;
        for(int j=1;j<=n;j++)
        {
            bool flag=false;
            for(auto x:vec[j])
            {
                if(x==i) all++,flag=true;
            }
            if(flag) t++;
        }
        cout<<t<<" "<<all<<'\n';
    }
}