#include<bits/stdc++.h>
using namespace std;
int main()
{
    double h,r;
    cin>>h>>r;
    double s=3.14*r*r;
    double v=h*s/1000;

    int cnt=1;
    while(v*cnt<20)
    {   
        cnt++;
    }
    cout<<cnt;
}