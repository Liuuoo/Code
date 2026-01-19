#include<bits/stdc++.h>
using namespace std;

double dfs(double x,double y,int n) //当前蛋糕x,y,分给n个人
{
    if(n==1) 
    {
        return max(x,y)/min(x,y);
    }
    double ans1,ans2; //横竖
    double ans=1e9; //所有切法中最小的
    for(int i=1;i<=n/2;i++) //枚举切的位置
    {   
        double x1=i*x/n;
        double x2=(n-i)*x/n;
        ans1=max(dfs(x1,y,i),dfs(x2,y,n-i));

        double y1=i*y/n;
        double y2=(n-i)*y/n;
        ans2=max(dfs(x,y1,i),dfs(x,y2,n-i));

        ans=min(ans,min(ans1,ans2)); 
    }
    return ans;
}

int main()
{
    double x,y; int n;
    cin>>x>>y>>n;
    cout<<fixed<<setprecision(6)<<dfs(x,y,n);
}