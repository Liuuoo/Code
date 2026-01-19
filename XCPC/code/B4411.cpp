#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        int tmp=x%10;
        bool flag=false;
        while(x)
        {
            if(tmp!=x%10)
            {
                flag=true;
            }
            x/=10;
        }
        if(!flag) cnt++;
    }
    cout<<cnt;
}