#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,l;
    cin>>a>>b>>l;
    double sd=a*1.0/b;
    double ans=1e9;
    int A,B;
    for(int i=0;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            double tmp=i*1.0/j;
            if(tmp-sd>=0&&__gcd(i,j)==1)
            {
                if(tmp<ans)
                {
                    A=i,B=j;
                    ans=tmp;
                }
            }
        }
    }
    cout<<A<<" "<<B;
}