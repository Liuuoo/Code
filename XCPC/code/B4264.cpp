#include<bits/stdc++.h>
using namespace std;
int box[555][555];

bool jud(int x,int y)
{
    return (box[x][y]*box[x+1][y+1]==box[x][y+1]*box[x+1][y]);
}

int main() 
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>box[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            cnt+=jud(i,j);
        }
    }
    cout<<cnt;
}