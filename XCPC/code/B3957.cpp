#include<bits/stdc++.h>
using namespace std;

bool jud(int x)
{
    int tmp=sqrt(x);
    return (tmp*tmp==x);
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(jud(a[i]+a[j]))
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
}