#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int tim=0;
    int tmp=0;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if(a>=90&&a<=140&&b>=60&&b<=90)
        {
            tmp++;
            tim=max(tim,tmp);
        }
        else tmp=0;
    }
    cout<<tim;
}