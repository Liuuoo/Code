#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int bod[N][N];
int t1[N][N],t2[N][N],t3[N][N],t4[N][N];
#define low_bit(x) (x&(-x))
int n,m;
void add(int x,int y,int k)
{
    for(int i=x;i<=n;i+=low_bit(i))
    {
        for(int j=y;j<=m;j+=low_bit(j))
        {
            t1[i][j]+=k;
            t2[i][j]+=x*k;
            t3[i][j]+=y*k;
            t4[i][j]+=x*y*k;
        }
    }
}
int sum(int x,int y)
{
    int res=0;
    for(int i=x;i>0;i-=low_bit(i))
    {
        for(int j=y;j>0;j-=low_bit(j))
        {
            res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
        }
    }
    return res;
}
int main()
{
    char X;  
    cin>>X>>n>>m;
    while(cin>>X)
    {
        if(X=='L')
        {
            int a,b,c,d,k;
            cin>>a>>b>>c>>d>>k;
            add(a,b,k);
            add(c+1,b,-k);
            add(a,d+1,-k);
            add(c+1,d+1,k);
        }
        else 
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            int ans=sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1);
            cout<<ans<<'\n';
        }
    }
}