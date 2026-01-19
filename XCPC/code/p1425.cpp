#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int mm=d-b;
    int hh=c-a;
    if(mm<0) 
    {
        hh--;
        mm+=60;
    }
    cout<<hh<<" "<<mm;
}