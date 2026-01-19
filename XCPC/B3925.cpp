#include<bits/stdc++.h>
using namespace std;
int n,k;

int jud(int x)
{   x=x*n+k;
    for(int i=0;i<n-1;i++)
    {
        if(x%(n-1)!=0) return 0;
        x=x/(n-1)*n+k;
    }
    return x;
}

int main()
{
    cin>>n>>k;
    int ans=1;
    while(1)
    {
        if(jud(ans))
        {
            cout<<jud(ans);
            break;
        }
        ans++;
    } 
}