#include<bits/stdc++.h>
using namespace std;
#define int long long

set<int> calc(int x)
{
    set<int>S;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            S.insert(i);
            S.insert(x/i);
        }
    }
    return S;
}

bool fid(set<int>S,int x)
{
    for(auto it:calc(x))
    {
        if(S.find(it)!=S.end()) return true;
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    int b[n+1];
    set<int>S1[n+1];
    set<int>S2[n+1];

    int a1[n+1]={0};
    int b1[n+1]={0};

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n-1;i++)
    {
        if(a[i]%a[i+1]!=0)
        {
            cout<<"NO\n";
            return;
        }
        if(a[i]==a[i+1]) a1[i+1]=-1;
        for(auto x:calc(a[i])) S1[i+1].insert(x);
    }

    for(int i=n-1;i>0;i--)
    {
        if(b[i]%b[i-1]!=0)
        {
            cout<<"NO\n";
            return;
        }
        if(b[i]==b[i-1]) b1[i-1]=-1;
        for(auto x:calc(b[i])) S2[i-1].insert(x);
    }

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(b[i]>a[i]||a[i]%b[i]!=0) 
            {
                cout<<"NO\n";
                return;
            }
        }
        else if(i==n-1)
        {
            if(a[i]>b[i]||b[i]%a[i]!=0) 
            {
                cout<<"NO\n";
                return;
            }
        }
        if(b[i]!=a[i])
        {
            int x=a[i];
            int y=b[i];

            if(max(x,y)%min(x,y)!=0)
            {
                if(a1[i]!=-1)
                {
                    if(fid(S1[i],y))
                    {
                        cout<<"NO\n";
                        return;
                    }
                    else 
                    {
                        for(auto it:calc(y)) S1[i+1].insert(it);
                    }
                }
                if(b1[i]!=-1)
                {
                    if(fid(S2[i],x))
                    {
                        cout<<"NO\n";
                        return;
                    }
                    else 
                    {
                        set<int>tmp=calc(b[i+1]);
                        if(fid(tmp,x)) 
                        {
                            cout<<"NO\n";
                            return;
                        }
                    }
                }
            }

            else 
            {
                int del=max(x,y)/min(x,y);
                if(x>y)
                {
                    if(b1[i]!=-1&&S2[i].find(del)!=S2[i].end())
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
                else 
                {
                    if(a1[i]!=-1&&S1[i].find(del)!=S1[i].end())
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES\n";
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
} 