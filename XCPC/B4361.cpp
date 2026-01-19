#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct Node{
    int h,w;
}a[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int h,w;
        cin>>h>>w;
        a[i]={h,w};
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=1;j--)
        {
            int h1=a[j].h;
            int w1=a[j].w;

            int h2=a[j-1].h;
            int w2=a[j-1].w;

            if(h1>h2)
            {
                swap(a[j],a[j-1]);
                cnt++;
            }

            else if(h1==h2)
            {
                if(w1>w2)
                {
                    swap(a[j],a[j-1]);
                    cnt++;
                }
            }
            
        }
    }
    cout<<cnt;
}