#include<bits/stdc++.h>
using namespace std;
int xx[]={1,1,-1,-1,0,0,1,-1};
int yy[]={1,-1,1,-1,-1,1,0,0};
const int N=110;
int box[N][N];

bool jud(int x,int y)
{
    for(int k=0;k<8;k++)
    {
        int ni=x+xx[k];
        int nj=y+yy[k];
        if(box[ni][nj]<box[x][y])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    memset(box,1,sizeof(box));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            box[i][j]=x;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(jud(i,j)) cnt++;
        }
    }
    cout<<cnt;
}   