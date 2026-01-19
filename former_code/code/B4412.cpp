#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int haf=(n+1)/2;
        int sp=abs(i-haf);
        int st=n-2*sp;
        for(int j=1;j<=sp;j++) cout<<".";
        for(int j=1;j<=st;j++)
        {
            if(j==1||j==st) cout<<"#";
            else cout<<".";
        }
        for(int j=1;j<=sp;j++) cout<<".";
        cout<<'\n';
    }
}