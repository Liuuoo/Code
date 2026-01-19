#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    int arr[n*m];
    for(int i=0;i<n*m;i++) 
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    int t=0;
    for(int i=1;i<=p;i++)
    {
        for(int j=1;j<=q;j++)
        {
            cout<<arr[t++]<<" ";
        }
        cout<<'\n';
    }
}