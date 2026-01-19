#include<bits/stdc++.h>
using namespace std;
char bod[101][101];
// 上左下右
int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1};
string dir="^<v>";

bool jud(int x,int y,int d)
{
    if(x==0||x==9||y==0||y==9) return false;
    else return true;
}

void move(pair<int,int>&p,int d,int dis)
{
    dis=min(dis,8);
    int x=p.first,y=p.second;
    
    while(jud(x,y,d)&&dis--)
    {
        bod[x][y]='.';
        int tx=x+xx[d];
        int ty=y+yy[d];
        // x+=xx[d];
        // y+=yy[d]; 
        if(jud(tx,ty,d)&&bod[tx][ty]!='.')
        {
            int nx=tx+xx[d];
            int ny=ty+yy[d];

            while(jud(nx,ny,d)&&bod[nx][ny]!='.')
            {
                nx+=xx[d];
                ny+=yy[d];
            }

            int nd=(d+2)%4;
            while(nx!=tx||ny!=ty)
            {
                int nnx=nx+xx[nd];
                int nny=ny+yy[nd];
                // if(!jud(nx,ny,d) || !jud(nnx,nny,d)) break;
                bod[nx][ny]=bod[nnx][nny];
                nx=nnx;
                ny=nny;
            }
        }
        if(jud(tx,ty,d)) x=tx,y=ty;
    }
    bod[x][y]=dir[d];
    p={x,y};
}

pair<int,int> calc(string s)
{
    if(s[0]=='t')
    {
        int t=0;
        while(s[t]!=' ') 
        {
            t++;
        }
        t++;
        if(s[t]=='l') return {0,0};
        if(s[t]=='r') return {0,1};
        else return {0,2};
    }
    else 
    {
        int t=0;
        while(s[t]!=' ') 
        {
            t++;
        }
        string tmp;
        t++;
        int cnt=0;
        for(int i=t;i<s.size()&&cnt<2;i++)
        {
            tmp+=s[i];
            cnt++;
        }
        // cout<<tmp<<'\n';
        return {1,min(8,stoi(tmp))};
    }
    return{-1,-1};
}

int main()
{
    pair<int,int>p;
    int d;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            char c;
            cin>>c;
            while(c=='\n'||c=='\r') cin>>c;
            bod[i][j]=c;
            if(!isalpha(c)&&c!='.')
            {
                p={i,j};
                if(c=='^') d=0;
                else if(c=='v') d=2;
                else if(c=='>') d=3;
                else d=1;
            }
        }
    }
    string s;
    getchar();
    while(getline(cin,s))
    {
        if(s.empty() || s[0]=='#') break;
        while(!s.empty()&&s.back()=='\n'||s.back()=='\r') s.pop_back();
        
        pair<int,int> stu=calc(s);
        if(stu.first==0)
        {
            if(stu.second==0) d=(d+1)%4;
            else if(stu.second==1) d=(d-1+4)%4;
            else d=(d+2)%4;
            bod[p.first][p.second]=dir[d];
        }
        else if(stu.first==1)
        {
            move(p,d,stu.second);
            // bod[p.first][p.second]=dir[d];
        }

        // for(int i=1;i<=8;i++)
        // {
        //     for(int j=1;j<=8;j++)
        //     {
        //         cout<<bod[i][j];
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n'<<'\n';

    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cout<<bod[i][j];
        }
        cout<<'\n';
    }
}