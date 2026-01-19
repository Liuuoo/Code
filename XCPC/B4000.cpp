#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,s;
    cin>>h>>m>>s;
    int k;
    cin>>k;
    while(k--)
    {
        s++;
        if(s>=60)
        {
            m++;
            s=0;
        }
        if(m>=60)
        {
            h++;
            m=0;
        }

    }
    cout<<h<<" "<<m<<' '<<s;
}