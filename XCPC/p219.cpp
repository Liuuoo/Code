#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long sum=(1+(long long)n)*n/2;
    for(int i=0;i<n-1;i++)
    {
        long long x;
        cin>>x;
        sum-=x;
    }
    cout<<sum;
}