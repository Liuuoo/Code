#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    int ans=0;
    cin>>a>>b;
    for(int i=a+1;i<b;i++)
    {
        if(i%400==0||(i%4==0&&i%100!=0))
        cout<<i<<'\n';
    }
    cout<<ans;
}