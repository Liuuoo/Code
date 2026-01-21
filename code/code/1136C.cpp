#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int b[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>b[i][j];
        }
    }
    multiset<int>B[max(n,m)+1];
    multiset<int> A[max(n,m)+1];
    for(int i=1;i<=m;i++)
    {
        int sum=1+i;
        for(int j=1;j<=n&&sum-j>=1;j++)
        {
            B[i].insert(b[j][sum-j]);
            A[i].insert(a[j][sum-j]);
        }
    }

    for(int i=1;i<=m;i++)
    {
        while(!A[i].empty())
        {
            if(*A[i].begin()!=*B[i].begin())
            {
                cout<<"NO"<<endl;
                return 0;
            }
            A[i].erase(A[i].begin());
            B[i].erase(B[i].begin());
        }
    }

    for(int i=1;i<=n;i++)
    {
        int sum=i+m;
        for(int j=i;j<=n&&sum-j>=1;j++)
        {
            int tmp=sum-j;
            B[i].insert(b[j][sum-j]);
            A[i].insert(a[j][sum-j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        while(!A[i].empty())
        {
            if(*A[i].begin()!=*B[i].begin())
            {
                cout<<"NO"<<endl;
                return 0;
            }
            A[i].erase(A[i].begin());
            B[i].erase(B[i].begin());
        }
    }
    cout<<"YES"<<endl;
}