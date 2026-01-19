#include<bits/stdc++.h>
using namespace std;
const int N=1234;
char box[N][N];
int cnt=0;
bool vis[N][N];
int xx[]={0,0,1,1,1,-1,-1,-1};
int yy[]={1,-1,0,1,-1,0,1,-1};
    int n,m;

void dfs(int noi,int noj)
{
    for(int i=0;i<8;i++)
    {
        int nxi=noi+xx[i];
        int nxj=noj+yy[i];

        if(box[nxi][nxj]=='W'&&!vis[nxi][nxj]&&nxi>=0&&nxj>=0&&nxi<n&&nxj<m)
        {
            vis[nxi][nxj]=true;
            dfs(nxi,nxj);
        }
    }
}

int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>box[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(box[i][j]=='W'&&vis[i][j]==0)  
            {
                cnt++;
                dfs(i,j);
            }  
    cout<<cnt;            
}