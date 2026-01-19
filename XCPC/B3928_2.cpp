#include<bits/stdc++.h>
using namespace std;
int box[23][23];
int n;

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    int i=0,j=0;
    while(j<n)
    {
        while(i<n&&a[i]<b[j]) i++;
        if(i>=n) break;
        i++;
        j++;
    }
    cout<<j;
}