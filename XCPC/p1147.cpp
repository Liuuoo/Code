#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int i=1,j=1;
    int sum=0;
    while(j<=m)
    {
        while(sum<m&&j<=m)
        {
            sum+=j;
            j++;
        }
        while(sum>=m)
        {
            if(sum==m&&j-i-1>=1)
            {
                cout<<i<<" "<<j-1<<'\n';
            }
            sum-=i;
            i++;
        }
    }
}