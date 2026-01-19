#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];
int n,r;
set<int>S;
bool check2()
{
    int t=n-1;
    while(a[t]!=1)
    {
        t--;
    }
    if(n-1-t>=r) return false;
    else return true;
}

int check()
{
    int cnt=1;
    int flag=-1;
    for(int i=0;i<r;i++)
    {
        if(a[i]==1)
        {
            flag=i;
        }
    }
    if(flag==-1) return flag;
 
    while(1)
    {
        bool jud=false;
        int i=flag;
        for(int j=i+1;j-i<r;j++)
        {
            if(a[j]==1) 
            {
                flag=j;
                jud=true;
            }
            if(j>=n-1) 
            {
                if(r==1) return n;
                else return cnt;
            }
        }
        i=i+r;
        for(int j=i;j-i<r;j++)
        {
            if(a[j]==1) 
            {
                flag=j;
                jud=true;
            }
            if(j>=n-1&&jud) 
            {
                if(r==1) return n;
                else 
                {
                    if(check2())  return cnt+1;
                    else return -1;
                }
            }
            if(j>=n-1&&!jud) return -1;
        }
        cnt++;
        if(!jud) return -1;
    }
}
 
int main()
{
 
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        S.insert(x);
    }
    if(r==1&&S.size()==1&&*S.begin()==1)
    {
        cout<<n;
    }
    else cout<<check();
}
