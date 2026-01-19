#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    // n=rand()%30+2;
    // k=rand()%(n*(n+1)/2+1);
    int a[n+1];
    int tmp=0;
    int i=1;
    for(i=1;i<=n;i++)
    {
        if(tmp+i>k) break;
        tmp+=i;
    }
    int num=2;
    for(int j=1;j<i;j++)
    {
        a[j]=num;
        num+=2;
    }
    int ii=i-1;
    int las=k-(ii*(ii+1)/2);
    int sum=0;
        a[0]=2;
    for(int j=i-1;j>=las;j--)
    {
        sum+=a[j];
    }
    a[i]=sum*-1+1;
    for(int j=i+1;j<=n;j++)
    {
        a[j]=-1000;
    }
    int pos=0,neg=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int s=0;
            for(int k=i;k<=j;k++)
            {
                s+=a[k];
            }
            if(s>0) pos++;
            else if(s<0) neg++;
        }
    }
    for(int j=1;j<=n;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<'\n';
}

int main()
{
    // srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}