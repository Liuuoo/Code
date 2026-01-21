#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,s;
    cin>>h>>m>>s;
    char c;
    cin>>c;
    int sum=s+m*60+h*60*60;
    if(c=='P')
    {
        sum+=12*60*60;
    }
    cout<<sum;
}