#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin>>x;
    // y_1=1
    // y_2=a
    // y_3=a+1=a*f_2+f_1
    // y_4=2a+1=a*f_3+f_2
    // y_5=3a+1=a*f_4+f_3

    // y_n=x
    // a*f_(n-1)+f_(n-2)=x
    // a=x-f_(n-2)/f_(n-1)

    cout<<2<<" "<<x<<'\n';
    int i=3;
    int f1=1,f2=1,now=2; // 表示前n-1 n-2项
    while(1)
    {

        int tmp=x-f2;
        if(tmp<=0) break;
        if(tmp%f1==0)
        {
            cout<<i<<" "<<tmp/f1<<'\n';
        }
        now=f1+f2;
        f2=f1;
        f1=now;
        i++;
    }

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    
}