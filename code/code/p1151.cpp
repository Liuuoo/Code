#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    bool flag=false;
    for(int i=10000;i<=30000;i++)
    {
        int a=i/100;
        int b=(i%10000)/10;
        int c=i%1000;
        if(a%k==0 && b%k==0 && c%k==0)
        {
            flag=true;
            cout<<i<<endl;
        }
    }
    if(!flag) cout<<"No"<<endl;
}