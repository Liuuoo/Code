#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool dp[N][N][N]; // 选了i个数，b的和为j,c的和为k

struct Node
{
    string s;
    int b,c;
};
vector<Node> vec;
bool vis[N];

int main()
{
    int n,m,b,c;
    cin>>n>>m>>b>>c;
    for(int i=0;i<n;i++)
    {
        string s;
        int b,c;
        cin>>s>>b>>c;
        vec.push_back({s,b,c});
    }
    dp[0][0][0]=true;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=min(i+1,m);j++)
        {
            for(int k=0;k<=b;k++)
            {
                for(int l=0;l<=c;l++)
                {
                    int bi=vec[i].b;
                    int ci=vec[i].c;
                    if(dp[j-1][k][l])
                    {
                        dp[j-1][k+bi][l+ci]=true;
                        if(k+bi>=b&&l+ci>=c)
                        {
                            vis[i]=true;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]) cout<<vec[i].s<<" ";
    }
}