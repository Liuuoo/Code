#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[4];
int minx=1,maxx=2,miny=1,maxy=2;
int d=0; // 0123 上右下左 
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};

bool calc1(pair<int,int>&np,int n,char c)
{
    int nd=d;
    if(c=='B') nd=(nd+2)%4; 
    np.first+=xx[nd];
    np.second+=yy[nd];
    for(int i=0;i<4;i++)
    {
        minx=min(minx,p[i].first);
        maxx=max(maxx,p[i].first);
        miny=min(miny,p[i].second);
        maxy=max(maxy,p[i].second);
        if(i==n) continue;
        if(np==p[i]) return false;
    }
    return true;
}

void change(pair<int,int>&p1,pair<int,int> p2)
{
    int x1=p2.first,y1=p2.second;
    int x2=p1.first,y2=p1.second;

    int dx=abs(y1-y2);
    int dy=abs(x1-x2);

    int x3,y3;
    if(x2>=x1&&y2>=y1) 
    {
        x3=x1+dx;
        y3=y1-dy;
    }
    else if(x2>=x1&&y2<=y1)
    {
        x3=x1-dx;
        y3=y1-dy;
    }
    else if(x2<=x1&&y2<=y1)
    {
        x3=x1-dx;
        y3=y1+dy;
    }
    else if(x2<=x1&&y2>=y1)
    {
        x3=x1+dx;
        y3=y1+dy;
    }
    p1={x3,y3};
}

void calc2(int n,char c)
{
    d++; d%=4;
    pair<int,int> np=p[n];
    for(int i=0;i<4;i++)
    {
        if(i!=n)
        {
            change(np,np);
        }
        minx=min(minx,p[i].first);
        maxx=max(maxx,p[i].first);
        miny=min(miny,p[i].second);
        maxy=max(maxy,p[i].second);
    }
}

int main()
{
    p[0]={1,1};
    p[1]={1,2};
    p[2]={2,1};
    p[3]={2,2};
    int n;
    cin>>n;
    bool jud=false;
    while(n--)
    {
        string s;
        cin>>s;
        char c=s.back();
        s.pop_back();

        int i;
        if(s=="FL") i=0;
        if(s=="FR") i=1;
        if(s=="RL") i=2;
        if(s=="RR") i=3;

        if(c!='P')
        {
            if(!calc1(p[i],i,c))
            {
                jud=true;
            }
        }
        else
        {
            calc2(i,c);
        }
        // cout<<d<<"\n";
        // for(int i=0;i<4;i++)
        // {
        //     cout<<p[i].first<<" "<<p[i].second<<'\n';
        // }
        // cout<<'\n';
    }
    if(!jud) cout<<(maxx-minx+1)*(maxy-miny+1);
    else cout<<"-1";
}