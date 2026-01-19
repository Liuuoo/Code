#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s;
    cin>>s;
    int ans=0;
    for(int i=1;i*i<=s;i++)
    {
        if(s%i==0)
        {
            ans++;
        }
    }
    cout<<ans;
}