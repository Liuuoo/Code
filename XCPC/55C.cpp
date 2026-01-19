#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    bool flag=false;
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        int d1=x-1;
        int d2=n-x;
        int d3=y-1;
        int d4=m-y;
        if(d1<5||d2<5||d3<5||d4<5)
        {
            cout<<"YES\n";
            flag=true;
            break;
        }
    }
    if(!flag) cout<<"NO\n";
}