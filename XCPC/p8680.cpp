#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=i;
        bool jud=false;
        while(tmp)
        {
            int num=tmp%10;
            
            if(num==2||num==0||num==1||num==9)
            {
                jud=true;
                break;
            }
            
            tmp/=10;
        }if(jud) sum+=i;
    }
    cout<<sum;
}