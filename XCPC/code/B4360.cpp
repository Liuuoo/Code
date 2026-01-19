#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,w;
    cin>>h>>w;
    int x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;
    string s[h+1];
    for(int i=1;i<=h;i++) cin>>s[i];
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1-1;j<y2;j++)
        {
            cout<<s[i][j];
        }
        cout<<'\n';
    }
}