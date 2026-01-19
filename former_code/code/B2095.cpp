#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double sum1=0;
    double a[n+1];
    double mx=-1,mi=1.0*INT_MAX;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum1+=a[i];
        mx=max(mx,a[i]);
        mi=min(mi,a[i]);
    }
    double avg1=sum1/n;
    double avg2=(sum1-mx-mi)/(n-2);
    printf("%.2f ",avg2);
    double ans=1.0*INT_MIN;
    bool flag1=false,flag2=false;
    for(int i=1;i<=n;i++)
    {
        if(!flag1&&a[i]==mi) flag1=true;
        else if(!flag2&&a[i]==mx) flag2=true;
        else ans=max(ans,abs(a[i]-avg2));
    }
    printf("%.2f ",ans);
}