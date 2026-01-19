#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double p=0.5*(a+b+c);
    double ans=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1lf",ans);
}