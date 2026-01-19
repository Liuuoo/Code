#include<bits/stdc++.h>
using namespace std;
#define int long long
int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
const int N=1e3+10;
int mx[N][N][2]; //0 1 下一步往右/下
int mi[N][N][2]; //0 1 右 下
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>bod(n+1);
    for(int i=1;i<=n;i++)
    {
        bod[i].resize(m+1);
        for(int j=1;j<=m;j++)
        {
            cin>>bod[i][j];
            mx[i][j][0]=mx[i][j][1]=INT_MIN;
            mi[i][j][0]=mi[i][j][1]=INT_MAX;
        }
    }
    for(int i=0;i<=n;i++) 
    {
        mx[i][0][0]=mx[i][0][1]=INT_MIN;
        mi[i][0][0]=mi[i][0][1]=INT_MAX;
    }
    for(int j=0;j<=m;j++)
    {
        mx[0][j][0]=mx[0][j][1]=INT_MIN;
        mi[0][j][0]=mi[0][j][1]=INT_MAX;
    }
    mx[1][1][0]=mx[1][1][1]=0;
    mi[1][1][0]=mi[1][1][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(bod[i][j]=='#') continue;
            if(i==j&&i==1) continue;
            if(j+1<=m&&bod[i][j+1]!='#') 
            {
                mx[i][j][0]=max(mx[i][j][0],mx[i-1][j][1]+1,mx[i][j-1][0]);
                mi[i][j][0]=min(mi[i][j][0],mi[i-1][j][1]+1,mi[i][j-1][0]);
            }
            else 
            {
                mx[i][j][0]=INT_MIN;
                mi[i][j][0]=INT_MAX;
            }
            if(i+1<=n&&bod[i+1][j]!='#')
            {
                mx[i][j][1]=max(mx[i][j][1],mx[i][j-1][0]+1,mx[i-1][j][1]);
                mi[i][j][1]=min(mi[i][j][1],mi[i][j-1][0]+1,mi[i-1][j][1]);
            }
            else 
            {   
                mx[i][j][1]=INT_MIN;
                mi[i][j][1]=INT_MAX;
            }
        }
    }

    int ans1=max(mx[n-1][m][1],mx[n][m-1][0]);
    int ans2=min(mi[n-1][m][1],mi[n][m-1][0]);

    if(bod[1][1]=='#'||ans1<=0) cout<<-1;
    else cout<<ans1<<" "<<ans2;

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         if(max(mx[i][j][1],mx[i][j][0])>=0) cout<<max(mx[i][j][1],mx[i][j][0]);
    //         else cout<<".";
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         if(min(mi[i][j][0],mi[i][j][1])<=12345) cout<<min(mi[i][j][0],mi[i][j][1]);
    //         else cout<<".";
    //     }
    //     cout<<'\n';
    // }
}