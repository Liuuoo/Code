#include<bits/stdc++.h>
using namespace std;
#define int long long

int to_bit(int x)
{
    int res = 0, k = 1;
    while (x >= k)
    {
        res ++;
        x -= k ++;
    }
    return res;
}

int calc(int x)
{
    map<int,int>M;
    for(int i=2;i<=x/i;i++)
    {
        while(x%i==0)
        {
            x/=i;
            M[i]++;
        }
    }
    if(x>1) M[x]++;
    int sum=0;
    for(auto x:M)
    {
        sum+=to_bit(x.second);
    }
    return sum;
}

signed main() 
{
    int n;
    cin>>n;
    cout<<calc(n);
}
