#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(x)
        {
            x=x&(x-1);
            cnt++;
        }
    }
    cout<<cnt<<" "<<(cnt&1);
}