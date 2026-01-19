#include<bits/stdc++.h>
using namespace std;

const int N=3e3+10;
int n;
int bod[N][N];
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};

set<int> del(int x)
{
    set<int> res;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            res.insert(i);
            x/=i;
        }
    }
    if(x>1) res.insert(x);
    return res;
}
set<int> calc(int x,int y)
{
    set<int> res;
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx<1||nx>n||ny<1||ny>n) continue;
        for(auto x:del(bod[nx][ny]))
        {
            res.insert(x);
        }
    }
    return res;
}
int main()
{
    cin>>n;
    int c=2;
    set<int>S;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2!=j%2) 
            {
                bod[i][j]=c;
                S.insert(c-1);
                c+=2;
            }
        }
    }

    for(int i=n*n;i<=n*n+40*n;i++) S.insert(i);

    int preVal=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2!=j%2) continue;

            set<int>tmp=calc(i,j);
            while(*S.begin()<preVal) S.erase(*S.begin());
            for(auto &x:S)
            {
                bool flag=false;
                set<int> yi=del(x);
                for(auto y:yi)
                {
                    if(tmp.find(y)!=tmp.end())
                    {
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                {
                    bod[i][j]=x;
                    preVal=x;
                    S.erase(x);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            assert(bod[i][j]!=0);
            if(i%2==j%2) cout<<bod[i][j]<<" ";
            else cout<<" ";
        }
        cout<<endl;
    }
}