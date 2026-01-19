#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int c='A'+i;
        while(c>'Z') c-=26;
        for(int j=0;j<n;j++)
        {
            while(c+j>'Z') c-=26;
            cout<<char(c+j);
        }
        cout<<'\n';
    }
}