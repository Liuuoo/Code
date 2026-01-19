#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0;
    double s=0;
    int k;
    cin>>k;
    while(s<=k)
    {
        n++;
        s+=1.0/n;
    }
    cout<<n;
}