#include<bits/stdc++.h>
using namespace std;
int day[]={0,31,-1,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m,d,h,k;
    cin>>y>>m>>d>>h>>k;
    h+=k;
    if(h>=24)
    {
        h-=24;
        d++;
        if(y%4==0&&y%100!=0||y%400==0)
            day[2]=29;
        else
            day[2]=28;

        if(d>day[m])
        {
            d-=day[m];
            m++;
            if(m>12)
            {
                m-=12;
                y++;
            }
        }
    }
    cout<<y<<" "<<m<<" "<<d<<" "<<h;
}