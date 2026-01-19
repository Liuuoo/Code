#include<bits/stdc++.h>
using namespace std;
#define int long long


int calc(int sum)
{
    return sum*(sum-1)/2;
}

double p(int i,int j,int sum)
{
    return i*j*1.0/calc(sum)*1.0;
}

signed main()
{
    // int mi= INT64_MAX;
    // for(int i=1;i<=1000;i++)
    // {
    //     for(int j=1;j<=1000;j++)
    //     {
    //         for(int k=1;k<=1000;k++)
    //         {
    //             int sum=i+j+k;
    //             if(p(i,j,sum)==517.0/2091.0
    //                 &&p(j,k,sum)==2632.0/10455.0
    //                 &&p(i,k,sum)==308.0/2091.0)
    //             {
    //                 if(mi>i+j+k)
    //                 {
    //                     mi=i+j+k;
    //                     cout<<i<<" "<<j<<" "<<k<<'\n';
    //                 }
    //             }
                
    //         }
    //     }
    // }
    cout<<55<<","<<94<<","<<56;
}