#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int h,w;
};
vector<Node>vec;
vector<Node>tmp(3333);
int cnt=0;

void merge(int l,int mid,int r)
{
    int p=l;
    int q=mid+1;
    for(int i=l;i<=r;i++)
    {
        if((q>r)||(p<=mid&&vec[p].h>vec[q].h)||(p<=mid&&vec[p].h==vec[q].h&&vec[p].w>=vec[q].w))
        {
            tmp[i]=vec[p++];
        }
        else 
        {
            tmp[i]=vec[q++];
            cnt+=mid-p+1;
        }
    }
    for(int i=l;i<=r;i++) vec[i]=tmp[i];
}

void merge_sort(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        vec.push_back({l,r});
    }
    merge_sort(0,vec.size()-1);
    cout<<cnt;
}