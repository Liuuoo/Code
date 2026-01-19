#include<bits/stdc++.h>
using namespace std;

int calc(int a,int b, int c)
{
    int sum=a+b+c-1;
    int ans=(sum+1)*sum/2;
    return ans;
}

int main() 
{
    // int a=1000,b=1000,c=1000;
    // int mi=INT_MAX;
    // for(int i=1;i<a;i++)
    // {
    //     for(int j=1;j<=b;j++)
    //     {
    //         for(int k=1;k<=c;k++)
    //         {
    //             double p12=i*j*1.0/calc(i,j,k);
    //             double p23=j*k*1.0/calc(i,j,k);
    //             double p13=i*k*1.0/calc(i,j,k);
    //             if(p12==517.0/2091&&p23==2632.0/10455&&p13==308.0/2091)
    //             {
    //                 mi=min(mi,i+j+k);
    //                 cout<<i<<" "<<j<<" "<<k<<'\n';
    //                 cout<<mi<<'\n';
    //             }
    //         }
    //     }
    // }
    string s="55,94,56";
    cout<<s;
}
