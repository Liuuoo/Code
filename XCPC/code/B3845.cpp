#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int c=i*i+j*j;
            int sc=sqrt(c);
            if(sc*sc==c&&sc<=n)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
}