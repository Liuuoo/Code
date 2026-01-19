#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    char a[n],b[n];
    bool flag=false;
    multiset<char>A;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        A.insert(a[i]);
    }
    multiset<char>B;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]!=a[i])
        {
            flag=true;
        }
        B.insert(b[i]);
    }
    while(!A.empty())
    {
        if(*A.begin()!=*B.begin())
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            A.erase(A.begin());
            B.erase(B.begin());
        }
    }
    if(!flag) 
    {
        cout<<"YES"<<endl;
    }
    else
    {
        int cnt=n-k;
        if(cnt<=0) cout<<"NO"<<endl;
        else 
        {
            for(int i=cnt+1;i<=n-cnt;i++)
            {
                if(a[i]!=b[i])
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
            cout<<"YES"<<endl;
        }

    }
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