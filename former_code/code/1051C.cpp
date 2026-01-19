#include<bits/stdc++.h>
using namespace std;
struct Map
{
    int sz;
    map<int,int>S;
    Map()
    {
        sz=0;
    }
    void insert(int x)
    {
        sz++;
        S[x]++;
    }
    int count(int x)
    {
        return S[x];
    }
    pair<int,int> max()
    {
        if(sz==0) return {-1,-1};
        else return {S.begin()->first,S.begin()->second};
    }
};
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    Map m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m.insert(a[i]);
    }
    int ans[n]={-1};
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(m.count(a[i])>1)
        {
            ans[i]=0;
        }
        else 
        {
            ans[i]=1;
            cnt++;
        }
    }
    if(cnt%2==0)
    {
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1)
            {
                ans[i]=t;
                t++;
                t%=2;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0) cout<<"A";
            else cout<<"B";
        }
    }
    else 
    {
        int flag=-1;
        for(int i=0;i<n;i++)
        {
            if(m.count(a[i])>2)
            {
                flag=i;
                ans[i]=1;
                break;
            }
        }
        if(flag==-1) 
        {
            cout<<"NO\n";
            return 0;
        }
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(i==flag) continue;
            if(ans[i]==1)
            {
                ans[i]=t;
                t++;
                t%=2;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0) cout<<"A";
            else cout<<"B";
        }
    }
}