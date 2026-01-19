#include<bits/stdc++.h>
using namespace std;
string box[12];
const int N=123;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};

int main()
{
    pair<int,int> f;
    pair<int,int> c;
    for(int i=0;i<10;i++) cin>>box[i];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(box[i][j]=='F') 
            {
                f={i,j};
                box[i][j]='.';
            }
            if(box[i][j]=='C') 
            {
                c={i,j};
                box[i][j]='.';
            }
        }
    }
    if(f==c) 
    {
        cout<<0;
        return 0;
    }
    int cnt=0;
    int ff=0,cc=0;
    while(cnt<N)
    {
        int pfx=f.first;
        int pfy=f.second;
        int pcx=c.first;
        int pcy=c.second;
        //cout<<pfx<<" "<<pfy<<" "<<pcx<<" "<<pcy<<'\n';
        int nfx=pfx+xx[ff];
        int nfy=pfy+yy[ff];
        if(nfx>=0&&nfy>=0&&nfx<10&&nfy<10&&box[nfx][nfy]=='.')
        {
            f={nfx,nfy};
        }
        else 
        {
            ff++;
            ff%=4;
        }
        
        int ncx=pcx+xx[cc];
        int ncy=pcy+yy[cc];
        if(ncx>=0&&ncy>=0&&ncx<10&&ncy<10&&box[ncx][ncy]=='.')
        {
            c={ncx,ncy};
        }
        else 
        {
            cc++;
            cc%=4;
        }

        cnt++;
        if(f==c) 
        {
            cout<<cnt;
            return 0;
        }
    }
    cout<<"0";
}