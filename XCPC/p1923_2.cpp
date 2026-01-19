#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int a[N];

int m_sort(int l,int r)
{
    int x=a[l];
    while(l<r)
    {
        while(l<r&&a[r]>=x) r--;
        if(l<r) a[l++]=a[r];
        while(l<r&&a[l]<=x) l++;
        if(l<r) a[r--]=a[l];
    }
    a[l]=x;
    return l;
}

int quick_sort(int l,int r, int k)
{
    if(l>=r) return l;
    int p=m_sort(l,r);
    if(k<=p) return quick_sort(l,p-1,k);
    else if(k>=p) return quick_sort(p+1,r,k);
    else return p;
}

int main()
{
    std::ios::sync_with_stdio(false);  
    std::cin.tie(nullptr);     
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p=quick_sort(0,n-1,k);
    cout<<a[p];
}