#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,w,h;

struct Node{
    int x;
    int y;
    int r;
};
vector<Node> vec;

int calc1(int low_x,int low_y)
{
    int up_x=low_x+w;
    int up_y=low_y+h;
    int ans=0;
    for(auto x:vec)
    {
        if(x.x-x.r>=low_x&&x.x+x.r<=up_x)
        {
            if(x.y-x.r>=low_y&&x.y+x.r<=up_y)
            {
                ans++;
            }
        }
    }
    return ans;
}

int calc2(int low_x,int low_y)
{
    int up_x=low_x+h;
    int up_y=low_y+w;
    int ans=0;
    for(auto x:vec)
    {
        if(x.x-x.r>=low_x&&x.x+x.r<=up_x)
        {
            if(x.y-x.r>=low_y&&x.y+x.r<=up_y)
            {
                ans++;
            }
        }
    }
    return ans;
}

signed main()
{

    cin>>n>>w>>h;
    int max_x,max_y,min_x,min_y;
    max_x=INT_MIN;
    max_y=INT_MIN;
    min_x=INT_MAX;
    min_y=INT_MAX;
    int ans=INT_MIN;
    while(n--)
    {
        int x,y,r;
        cin>>x>>y>>r;
        min_x=min(min_x,x-r);
        min_y=min(min_y,y-r);
        max_x=max(max_x,x+r);
        max_y=max(max_y,y+r);
        vec.push_back({x,y,r});
    }
    cout<<min_x<<" "<<max_x<<" "<<min_y<<" "<<max_y<<'\n';
    for(int i=min_x;i<=max_x;i++)
    {
        for(int j=min_y;j<=max_y;j++)
        {
            ans=max(ans,calc1(i,j));
            ans=max(ans,calc2(i,j));
        }
    }
    cout<<ans;
}