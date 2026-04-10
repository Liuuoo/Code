#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int a[10];
void dfs(int n,int x)
{
    if(n>=(x+1)/2) 
    {
        if(x==1) 
        {
            vec.push_back(a[0]);
            return;
        }
        else 
        {
            int t1=n-1,t2=n,num=0; // t1向前，t2向后
            if(x%2!=0) t1--;
            for(int i=t1;i>=0;i--) a[t2++]=a[i];
            for(int i=0;i<t2;i++) num+=a[i]*pow(10,i);
            vec.push_back(num);
            return;
        }
    }
    for(int i=(n==0?1:0);i<=9;i++)
    {
        a[n]=i;
        dfs(n+1,x);
    }
}

bool is_prime(int x)
{
    if(x<=1) return false;
    if(x==2) return true;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    } 
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    string sn=to_string(n);
    string sm=to_string(m);
    for(int i=sn.size();i<=sm.size();i++) dfs(0,i);
    for(auto x: vec)
    {
        if(x>=n&&x<=m && is_prime(x))
        {
            cout<<x<<'\n'; 
        }
        if(x>m) break;
    }
}