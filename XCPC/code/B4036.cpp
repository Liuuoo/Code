#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() 
{
    int n;
    cin>>n;
    int sum=0;
    while(n--)
    {
        int x;
        cin>>x;
        int tmp=0;
        while(x)
        {
            tmp+=x%10;
            x/=10;
        }
        sum=max(sum,tmp);
    }
    cout<<sum;
}