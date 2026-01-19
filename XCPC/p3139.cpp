#include<bits/stdc++.h>
using namespace std;
int X,Y,K,M;
int ans=INT_MAX;
set<pair<pair<int,int>,int>> vis;
void dfs(int x,int y,int k) // x,y为x-y-桶中剩下的 k为剩余的次数
{
    // cout<<x<<" "<<y<<" "<<k<<" "<<(M-x-y)<<endl;
    // assert((M-x-y)!=0);
    ans=min(ans,abs(x+y-M));
    if(vis.find({{x,y},k})!=vis.end()) return; 
    vis.insert({{x,y},k});
    if(k==0) return;

    int addy=min((Y-y),x);
    int addx=min((X-x),y);

    if(addy!=0) dfs(x-addy,y+addy,k-1);
    if(addx!=0) dfs(x+addx,y-addx,k-1);

    dfs(0,y,k-1);
    dfs(x,0,k-1);

    if(x<X) dfs(X,y,k-1);
    if(y<Y) dfs(x,Y,k-1);

}
int main()
{
    cin>>X>>Y>>K>>M;
    dfs(0,0,K);
    cout<<ans;
}