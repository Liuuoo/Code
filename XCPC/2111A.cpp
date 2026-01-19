#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[3]={0};
    int cnt=0;
    while(a[0]<n)
    {
        cnt++;
        int t1=a[1]*2+1;
        int t2=a[2]*2+1;
        // cout<<t1<<" "<<t2<<' '<<a[1]<<" "<<a[2]<<'\n';
        int i;
        if(a[1]==0||a[2]==0)
        {
            a[0]=1;
        }
        else {

                if(t2/2<=a[1])
                {
                   a[0]=t2;
                }
                
                else
                {
                    a[0]=t1;
                }

        }
        sort(a,a+3);
       //for(int i=0;i<3;i++) cout<<a[i]<<" ";cout<<'\n';
    }

    cout<<cnt<<'\n';
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    solve();
}
