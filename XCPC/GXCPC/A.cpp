#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
set<int> c;
 int main()
{
    int n_1,n_2,n_3;
    cin>>n_1>>n_2>>n_3;
    for(int i=0;i<n_1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n_2;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n_3;i++)
    {
        int x;
        cin>>x;
        c.insert(x);
    }
    set<int> c2;
    for(int i=0;i<n_1;i++)
    {
        for(int j=0;j<n_2;j++)
        {
            int sum=a[i]+b[j];
            c2.insert(sum);
        }
    }
    if(c2==c) cout<<"YES";
    else cout<<"NO";
}