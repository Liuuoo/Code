#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int i=0;
    int len=1;
    while(i<n)
    {
        int j=i+1;
        while(j<n&&a[j]==a[j-1]+1)
        {
            j++;
        }
        len=max(len,j-i);
        i=j;
    }
    cout<<len;
}