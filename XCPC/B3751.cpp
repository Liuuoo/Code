#include <bits/stdc++.h>
using namespace std;
const int N=60;
char box[N][N];
int main() 
{
    memset(box,'.',sizeof(box));
    int n,m,k;
    cin>>n>>m>>k;
    while(k--)
    {
        int x,y;
        char c,d;
        cin>>x>>y>>c>>d;
        if(d=='R')
        {
            for(int i=y;i<=m;i++) box[x][i]=c;
        }
        else if(d=='L') 
        {
            for(int i=1;i<=y;i++) box[x][i]=c;
        }
            
        else if(d=='U')
        {
            for(int i=1;i<=x;i++) box[i][y]=c;
        }
        else 
        {
            for(int i=x;i<=n;i++) box[i][y]=c;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<box[i][j];
        cout<<'\n';
    }
}
