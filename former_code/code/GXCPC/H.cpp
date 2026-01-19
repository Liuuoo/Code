#include<bits/stdc++.h>
using namespace std;
vector<int> pm={31,29,31,30,31,30,31,31,30,31,30,31};
vector<int> rm={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{    
    int ty=2025;
    int tm=9;
    int td=18;
    int ans=0;
    int y,m,d;
    cin>>y>>m>>d;
    while(ty!=y||tm!=m||td!=d) 
    {
        //cout<<y<<" "<<m<< " "<<d<<'\n';
        d++;
        ans++;
        if(y==2020||y==2024)
        {
            if(d==pm[m-1]+1)
            {
                m++;
                d=1;
            }
        }
        else{
            if(d==rm[m-1]+1)
            {
                m++;
                d=1;
            }
        }
        if(m==13)
        {
            m=1;
            y++;
        }
    }
    cout<<ans;
}