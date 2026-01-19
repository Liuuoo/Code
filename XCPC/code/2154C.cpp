#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    set<int>S;
    int a[n+1];
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        S.insert(a[i]);
    }
    for(int i=1;i<=n;i++) 
    {
        int y; cin>>y;
    }
    map<int,int>M;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        bool flag=false;
        for(int j=2;j*j<=x;j++)
        {
            flag=false;
            while(x%j==0)
            {
                x/=j;
                if(!flag)
                {
                    flag=true;
                    M[j]++;
                }
            }
        }
        if(x>=2) M[x]++;
    }
    for(int t=0;t<=1;t++)
    {
        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            bool flag=false;
            for(int j=2;j*j<=x;j++)
            {
                flag=false;
                while(x%j==0)
                {
                    x/=j;
                    if(!flag)
                    {
                        flag=true;
                        M[j]--;
                    }
                }
            }
            if(x>=2) M[x]--;

            x=a[i]+t;
            
            for(int j=2;j*j<=x;j++)
            {
                flag=false;
                while(x%j==0)
                {
                    x/=j;
                    if(!flag)
                    {
                        flag=true;
                        M[j]++;
                        if(M[j]>=2)
                        {
                            cout<<t<<'\n';
                            return;
                        }
                    }
                }
            }
            if(x>=2)
            {
                M[x]++;
                if(M[x]>=2)
                {
                    cout<<t<<'\n';
                    return;
                }
            }

            x=a[i]+t;
            flag=false;
            for(int j=2;j*j<=x;j++)
            {
                flag=false;
                while(x%j==0)
                {
                    x/=j;
                    if(!flag)
                    {
                        flag=true;
                        M[j]--;
                    }
                }
            }
            if(x>=2)
            {
                M[x]--;
            }

            x=a[i];
            flag=false;
            for(int j=2;j*j<=x;j++)
            {
                flag=false;
                while(x%j==0)
                {
                    x/=j;
                    if(!flag)
                    {
                        flag=true;
                        M[j]++;
                    }
                }
            }
            if(x>=2) M[x]++;
        }
    }
    cout<<"2\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}