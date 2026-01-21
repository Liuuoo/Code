#include<bits/stdc++.h>
using namespace std;
int n,k;

int jud(int x)
{
    x=x*n+k; //最后一只猫不需要分鱼了，从倒数第二只算（都需要分鱼）
    for(int i=1;i<n;i++)
    {
        if(x%(n-1)!=0) return 0;
        x=x/(n-1)*n+k;
    }
    return x;
}

int main()
{
    cin>>n>>k;
    int cnt=1;
    while(1)
    {
        if(jud(cnt))
        {
            cout<<jud(cnt);
            break;
        }
        cnt++;
    }
}