#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int>calc(int x1,int y1,int x2,int y2)
{
    int x=x2-x1+1;
    int y=y2-y1+1;
    int sum=x*y;
    if(x1%2==y1%2&&x2%2==y2%2)
    {
        return {(sum+1)/2,sum/2};
    }
    else if(x1%2!=y1%2&&x2%2!=y2%2)
    {
        return {sum/2,(sum+1)/2};
    }
    else 
    {
        return {sum/2,sum/2};
    }
}

void solve()
{
    int n,m;
    cin>>m>>n;
    int w=(n*m+1)/2;
    int b=n*m/2;
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;

    if(x3<=x2&&y3<=y2&&x4>=x1&&y4>=y1)
    {
        int xx1=max(x1,x3);
        int yy1=max(y1,y3);
        int xx2=min(x4,x2);
        int yy2=min(y4,y2);
        
        w+=calc(x1,y1,x2,y2).second-calc(x3,y3,x4,y4).first-calc(xx1,yy1,xx2,yy2).second;
        b+=calc(x3,y3,x4,y4).first-calc(x1,y1,x2,y2).second+calc(xx1,yy1,xx2,yy2).second;
    }

    else 
    {
        w+=calc(x1,y1,x2,y2).second-calc(x3,y3,x4,y4).first;
        b+=calc(x3,y3,x4,y4).first-calc(x1,y1,x2,y2).second;
    }

    cout<<w<<" "<<b<<'\n';
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}