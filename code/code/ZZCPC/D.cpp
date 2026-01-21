#include<bits/stdc++.h>
using namespace std;
int mian()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    multiset<int>A[2],B[2];
    for(int i=0;i<n;i++)
    {
        if(A[0].empty()) A[0].insert(a[i]);
        else 
        {
            if(A[0].find(a[i])!=A[0].end())
            {
                A[0].erase(A[0],find(a[i]));
            }
        }
        if(B[0].empty()) B[0].insert(b[i]);
    }
}