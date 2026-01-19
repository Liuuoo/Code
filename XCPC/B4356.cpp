#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int cnt=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=i;j<=a;j++)
        {
            if((i*j)%2==0) cnt++;
        }
    }
    cout<<cnt;
}