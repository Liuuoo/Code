#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,r;
    cin>>l>>r;
    int cnt=0;
    for(int i=0;pow(2,i)<=r;i++)
    {
        for(int j=i;pow(2,i)+pow(2,j)<=r;j++)
        {
            if(pow(2,i)+pow(2,j)>=l&&pow(2,i)+pow(2,j)<=r)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
}