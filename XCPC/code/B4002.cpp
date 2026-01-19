#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        bool flag=false;
        for(int i=1;i*i<x;i++)
        {
            int j=x-(i*i);
            int s=sqrt(j);
            if(s*s==j) 
            {
                cout<<"Yes\n";
                flag=true;
                break;
            }
        }   
        if(!flag) cout<<"No\n";
    }
}