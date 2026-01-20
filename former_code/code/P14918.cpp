#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main()
{
    int n;
    cin>>n;
    map<int,int> vec[N];
    set<int> S;
    vector<int> num[N];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for(int j=2;j*j<=x;j++)
        {
            while(x%j==0)
            {
                vec[i][j]++;
                x/=j;
                S.insert(j);
            }
        }
        if(x>=2)
        {
            vec[i][x]++;
            S.insert(x);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(auto x:vec[i])
        {
            num[x.first].push_back(x.second);
        }
    }
    vector<int> pre_sum[N];
    for(auto x: S)
    {
        sort(num[x].begin(),num[x].end());
        pre_sum[x].resize(num[x].size()+1);
        pre_sum[x][0]=0;
        for(int i=1;i<=num[x].size();i++)
        {
            pre_sum[x][i]+=pre_sum[x][i-1]+num[x][i-1];
        }
    }
    int ans=0;
    for(auto x: S)
    {
        int t_sum=INT_MAX;
        for(int j=0;j<=num[x].back();j++)
        {
            int z=n-num[x].size();
            int idx=lower_bound(num[x].begin(),num[x].end(),j)-num[x].begin();
            int calc= j*idx - pre_sum[x][idx]+ (pre_sum[x][num[x].size()]-pre_sum[x][idx])-j*(num[x].size()-idx) +z*j;
            t_sum=min(t_sum,calc);
        }
        ans+=t_sum;
    }
    cout<<ans;
}