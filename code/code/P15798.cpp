#include<bits/stdc++.h>
using namespace std;

bool jud(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            if(i!=2&&i!=5) return false;
            x/=i;
        }
    }
    if(x==1||x==2||x==5) return true;
    else return false;
}

int main()
{
    int l,r;
    cin>>l>>r;
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        if(jud(i)) cnt++;
    }
    cout<<cnt;
}