#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int cnt=0;
    int num=1;
    while(1)
    {
        bool jud=false;
        for(int i=1;i<=num;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i*i-j*j==num)
                {
                    cnt++;
                    jud=true;
                }
            }
            if(jud) break;
        }
        if(cnt==n) break;
        num++;
    }
    cout<<num;
}