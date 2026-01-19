#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int b[N],c[N],a[N],t[N];

struct Node
{
    int v; //代价
    map<int,int>M;
};

int main()
{
    int n,m,v;
    cin>>n>>m>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        b[i]=x; c[i]=y;
    }
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=x; t[i]=y;
        sum+=x;
    }
    vector<Node>prev(v+10),curr(v+10);
    map<int,int>MMM;
    for(int i=0;i<=v+1;i++)
    {
        
        prev[i]={-1,MMM};
        curr[i]={-1,MMM};
    }
    prev[0]={0,MMM};
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=v+1;j++)
        {
            if(prev[j].v!=-1)
            {
                int tmp=c[t[i]]+b[t[i]];
                map<int,int>M=prev[j].M;
                for(auto x:M)
                {
                    if(x.second&&x.first==t[i])
                    {
                        tmp-=b[t[i]];
                        break;
                    }
                }
                M[t[i]]++;
                //选择
                int nt=min(v+1,j+a[i]);
                if(curr[nt].v==-1)
                {
                    curr[nt].v=prev[j].v+tmp;
                    curr[nt].M=M;
                }
                else //存在
                {
                    if(curr[nt].v>prev[j].v+tmp)
                    {
                        curr[nt].v=prev[j].v+tmp;
                        curr[nt].M=M;
                    }
                }
                //不选
                // dp[i][j]=dp[i-1][j];
                if(curr[j].v>prev[j].v||curr[j].v==-1) curr[j]=prev[j];
            }
        }
        prev.swap(curr);
    }
    // int ans=INT_MAX;
    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=v+1;j<=sum;j++)
    //     {
    //         if(dp[i][j].v!=-1) ans=min(dp[i][j].v,ans);
    //     }
    // }
    cout<<prev[v+1].v;
}
