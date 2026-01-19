#include<bits/stdc++.h>
using namespace std;
// pair<int,int> p[4];
// int minx=1,maxx=2,miny=1,maxy=2;
// int d=0; // 0123 上右下左 
// int xx[]={-1,0,1,0};
// int yy[]={0,1,0,-1};

// bool calc1(pair<int,int>&np,int n,char c)
// {
//     int nd=d;
//     if(c=='B') nd=(nd+2)%4; 
//     np.first+=xx[nd];
//     np.second+=yy[nd];
//     for(int i=0;i<4;i++)
//     {
//         minx=min(minx,p[i].first);
//         maxx=max(maxx,p[i].first);
//         miny=min(miny,p[i].second);
//         maxy=max(maxy,p[i].second);
//         if(i==n) continue;
//         if(np==p[i]) return false;
//     }
//     return true;
// }

// void change(pair<int,int>&p1,pair<int,int> p2)
// {
//     int x1=p2.first,y1=p2.second;
//     int x2=p1.first,y2=p1.second;

//     int dx=abs(y1-y2);
//     int dy=abs(x1-x2);

//     int x3,y3;
//     if(x2>=x1&&y2>=y1) 
//     {
//         x3=x1+dx;
//         y3=y1-dy;
//     }
//     else if(x2>=x1&&y2<=y1)
//     {
//         x3=x1-dx;
//         y3=y1-dy;
//     }
//     else if(x2<=x1&&y2<=y1)
//     {
//         x3=x1-dx;
//         y3=y1+dy;
//     }
//     else if(x2<=x1&&y2>=y1)
//     {
//         x3=x1+dx;
//         y3=y1+dy;
//     }
//     p1={x3,y3};
// }

// void calc2(int n,char c)
// {
//     d++; d%=4;
//     pair<int,int> np=p[n];
//     for(int i=0;i<4;i++)
//     {
//         if(i!=n)
//         {
//             change(p[i],np);
//         }
//         minx=min(minx,p[i].first);
//         maxx=max(maxx,p[i].first);
//         miny=min(miny,p[i].second);
//         maxy=max(maxy,p[i].second);
//     }
// }
// struct kk{
//     int x,y;
// }a[5];

// int solve1()
// {
//     freopen("p2206_in.txt","r",stdin);
//     p[0]={1,1};
//     p[1]={1,2};
//     p[2]={2,1};
//     p[3]={2,2};
//     int n;
//     cin>>n;
//     bool jud=false;
//     while(n--)
//     {
//         string s;
//         cin>>s;
//         char c=s.back();
//         s.pop_back();

//         int i;
//         if(s=="FL") i=0;
//         if(s=="FR") i=1;
//         if(s=="RL") i=2;
//         if(s=="RR") i=3;

//         if(c!='P')
//         {
//             if(!calc1(p[i],i,c))
//             {
//                 jud=true;
//             }
//         }
//         else
//         {
//             calc2(i,c);
//         }
//         // cout<<d<<"\n";
//         // for(int i=0;i<4;i++)
//         // {
//         //     cout<<p[i].first<<" "<<p[i].second<<'\n';
//         // }
//         // cout<<'\n';
//     }
//     if(!jud) return(maxx-minx+1)*(maxy-miny+1);
//     else return -1;
// }

// int solve2()
// {
//     freopen("p2206_in.txt","r",stdin);
//     char F[255],G[255],s[4],T[255];
//     int foot,k,j,i,xx,yy,minx,miny,maxx,maxy,b[4][2]={{-1,0},{0,1},{1,0},{0,-1}},n,t;
//     F['F']=0;F['R']=1;F['B']=2;F['L']=3;F['P']=4;//判断前进方向
//     G['F']=0;G['R']=1;T['L']=0;T['R']=1;//判断是哪只脚
//     cin>>n;
//     a[1].y=a[2].x=a[3].x=a[3].y=1;
//     maxx=maxy=1;
//     for (i=1;i<=n;i++){
//         scanf("%s",s);
//         foot=G[s[0]]*2+T[s[1]];
//         k=F[s[2]];
//         if (k<4) a[foot].x+=b[(k+t)%4][0],a[foot].y+=b[(k+t)%4][1];//在我的方法中，前进方向加朝向模4就是去的方向
//           else{
//               t=(t+1)%4;//转向
//             for (j=0;j<4;j++) xx=a[j].y-a[foot].y+a[foot].x,yy=a[foot].x-a[j].x+a[foot].y,a[j].x=xx,a[j].y=yy;
//         }
//         for (j=0;j<4;j++)
//             for (k=j+1;k<4;k++)
//                 if (a[j].x==a[k].x && a[j].y==a[k].y){
                    
//                     return -1;
//                 }
//         for (j=0;j<4;j++) minx=min(minx,a[j].x),maxx=max(maxx,a[j].x),miny=min(miny,a[j].y),maxy=max(maxy,a[j].y);
//     }
//     return(maxx-minx+1)*(maxy-miny+1);
// }

int main()
{
    srand(time(0));
    while(1)
    {
        freopen("p2206_in.txt","w",stdout);
        int n=4;
        cout<<n<<'\n';
        while(n--)
        {
            int a=rand()%4;
            string s;
            if(a==0) s="RL";
            else if(a==1) s="RR";
            else if(a==2) s="FL";
            else s="FR";
            int b=rand()%3;
            if(b==0) s+='F';
            else if(b==1) s+='B';
            else s+='P';
            cout<<s<<'\n';
        }
        if(solve1()!=solve2())
        {
            cout<<solve1()<<" "<<solve2()<<'\n';
            // break;
        }
    }

}