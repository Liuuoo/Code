#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
bool check(int x)
{
    int las=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x) continue;
        else if(a[i]==las) las=-1;
        else 
        {
            if(las==-1) las=a[i];
            else return false;
        }
    }
    return true;
}

int main()
{
    cin>>n;
    a.resize(n+1);
    vector<int> vec(n+1);
    vec[0]=-1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        vec[i]=x;
    }
    sort(vec.begin(),vec.end());
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(vec[mid]))
        {
            r=mid;
        }
        else l=mid+1;
    }
    cout<<vec[r];
}