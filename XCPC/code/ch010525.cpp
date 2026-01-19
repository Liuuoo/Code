#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    //要满足都是三位，即666(7) 888(9)即342(10)与728(10)
    //且100(7)=49(10) 100(9)=81(10)
    //所以这边取最小值最大，最大值最小来确保在区间内

    for(int i=81;i<=342;i++)
    {
        int a7=i/7/7;
        int b7=(i/7)%7;
        int c7=(i%7);

        int a9=i/81;
        int b9=(i/9)%9;
        int c9=i%9;
        if(a7==c9&&b7==b9&&c7==a9)
        {
            cout<<i<<"\n";
            cout<<a7<<b7<<c7<<'\n';
            cout<<a9<<b9<<c9;
            break;
        }
   }
}