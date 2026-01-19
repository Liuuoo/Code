#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> M;

int calc(int x)
{
    int res=0;
    for(int i=2;i<=x/i;i++)
    {
        while(x%i==0)
        {
            x/=i;
            M[i]++;
        }
    }
    if(x>=2) M[x]++;

    for(auto &x:M)
    {
        int cnt=1;
        while(x.second>=cnt)
        {
            x.second-=cnt;
            res++;
            cnt++;
        }
    }
    return res;
}

signed main()
{
    int n;
    cin>>n;
    cout<<calc(n);
}