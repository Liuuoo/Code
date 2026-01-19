#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    map<int,int>m;
    for(int i=1;i<=d;i++){
        int x;
        cin>>x;
        m[x]+=i;
    }
    for(int i=0;i<n;i++) cout<<m[i]<<" ";
}