#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int day=1;
    int coin=1;
    int sum=0;
    while(day<=n)
    {
        for(int i=1;i<=coin;i++)
        {
            sum+=coin;
            day++;
            if(day>n) break;
        }
        coin++;
    }
    cout<<sum;
}