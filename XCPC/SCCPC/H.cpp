#include<bits/stdc++.h>
using namespace std;
#define ll long long
// int xx[]={1,1,-1,-1,2,2,-2,-2,1,1,-1,-1,2,2,-2,-2};
// int yy[]={1,-1,1,-1,2,-2,2,-2,2,-2,2,-2,1,-1,1,-1};
// int solve1(int x,int y,int X,int Y)
// {
//     queue<pair<int,int>>q;
//     q.push({x,y});
//     map<pair<int,int>,bool>vis;
//     map<pair<int,int>,int>step;
//     vis[{x,y}]=1;
//     step[{x,y}]=0;
//     while(!q.empty())
//     {
//         pair<int,int>p=q.front();
//         q.pop();
//         if(p.first==X && p.second==Y)
//         {
//             break;
//         }
//         for(int i=0;i<16;i++)
//         {
//             int nx=p.first+xx[i];
//             int ny=p.second+yy[i];
//             if(!vis[{nx,ny}])
//             {
//                 q.push({nx,ny});
//                 vis[{nx,ny}]=1;
//                 step[{nx,ny}]=step[p]+1;
//             }
//         }
//     }
//     return step[{X,Y}];
// }

ll solve2(int x,int y,int X,int Y)
{
    ll dx=abs(x-X);
    ll dy=abs(y-Y);
    ll mind=min(dx,dy);
    ll maxd=max(dx,dy);
    ll res=(maxd+1)/2;
    if(res==0) return 0;
    if(res==1) 
    {
        if(mind==0) return 2;
        else return 1;
    }
    else 
    {
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // srand(time(0));
    int T;
    cin>>T;
    while(T--)
    {
        int x,y,X,Y;
        cin>>x>>y>>X>>Y;
        // x=rand()%10*pow(-1,rand()%2);
        // y=rand()%10*pow(-1,rand()%2);
        // X=rand()%10*pow(-1,rand()%2);
        // Y=rand()%10*pow(-1,rand()%2);
        // int ans1=solve1(x,y,X,Y);
        int ans2=solve2(x,y,X,Y);
        cout<<ans2<<endl;
        // if(ans1!=ans2)
        // {
        //     cout<<x<<" "<<y<<" "<<X<<" "<<Y<<" "<<ans1<<" "<<ans2<<endl;
        //     cout<<ans1<<" "<<ans2<<endl;
        //     break;
        // }
        // else
        // {
        //     cout<<"OK"<<endl;
        // }
    }
}