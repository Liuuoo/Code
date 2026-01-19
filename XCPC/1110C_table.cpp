#include<bits/stdc++.h>
using namespace std;
const int N=4e8+5;
int main()
{
    int i=1;
    while(i<=N)
    {
        int ans=0;
        for(int j=1;j<i;j++)
        {
            ans=max(ans,(__gcd((i^j),(i&j))));
        }
        cout<<i<<" "<<ans<<endl;
        i<<=1;
        i=(i|1);
    }
}