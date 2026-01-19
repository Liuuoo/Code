#include<bits/stdc++.h>
using namespace std;
// 0左 1右 2下
int xx[]={0,0,1,-1};
int yy[]={-1,1,1,-1};
int box[1005][1005];
bool vis[1005][1005][10];
int step[1005][1005][10];
// map<pair<int,int>,bool>vis;
struct Node
{
    int x,y;
    int c;
    int d; //底下的数往哪指向 0上 1下 2左上 3左下 4右上 5右下
};
pair<bool,int> jud(Node a,int p,int c)
{
    if(a.d==0) //指上
    {
        if(p==0) // 向左
        {
            if(a.c==3) return {(c==1),4};
            else if(a.c==1) return {(c==2),4};
            else if(a.c==2) return {(c==3),4};
            else if(a.c==4) return {(c==1),2};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==2),2};
            else if(a.c==1) return {(c==3),2};
            else if(a.c==2) return {(c==1),2};
            else if(a.c==4) return {(c==3),4};
        }
        else if(p==2) // 下
        {
            if(a.c==1) return {(c==4),4};
            else if(a.c==2) return {(c==4),1};
            else if(a.c==3) return {(c==4),2};
            else if(a.c==4) return {(c==2),1};
        }
        else return {false,-1};
    }
    else if(a.d==1) // 下
    {
        if(p==0) // 向左
        {
            if(a.c==3) return {(c==2),5};
            else if(a.c==1) return {(c==3),5};
            else if(a.c==2) return {(c==1),5};
            else if(a.c==4) return {(c==3),3};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==1),3};
            else if(a.c==1) return {(c==2),3};
            else if(a.c==2) return {(c==3),3};
            else if(a.c==4) return {(c==1),5};
        }
        else if(p==3) // 向上
        {
            if(a.c==3) return {(c==4),5};
            else if(a.c==1) return {(c==4),3};
            else if(a.c==2) return {(c==4),0};
            else if(a.c==4) return {(c==2),0};
        }
        else return {false,-1};
    }

    else if(a.d==2) // 左上
    {
        if(p==0) // 向左
        {
            if(a.c==3) return {(c==1),0};
            else if(a.c==1) return {(c==2),0};
            else if(a.c==2) return {(c==3),0};
            else if(a.c==4) return {(c==1),3}; //here
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==4),3};
            else if(a.c==1) return {(c==4),0};
            else if(a.c==2) return {(c==4),5};
            else if(a.c==4) return {(c==2),5}; //here
        }
        else if(p==3)
        {
            if(a.c==3) return {(c==2),3}; 
            else if(a.c==1) return {(c==3),3};
            else if(a.c==2) return {(c==1),3};
            else if(a.c==4) return {(c==3),0};
        }
        else return {false,-1};
    }
    else if(a.d==3) // 左下
    {
        if(p==0) // 向左
        {
            if(a.c==3) return {(c==2),1}; // is here!
            else if(a.c==1) return {(c==3),1};
            else if(a.c==2) return {(c==1),1};
            else if(a.c==4) return {(c==3),2};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==4),1}; 
            else if(a.c==1) return {(c==4),2};
            else if(a.c==2) return {(c==4),4};
            else if(a.c==4) return {(c==2),4};
        }
        else if(p==2) // 下
        {
            if(a.c==3) return {(c==1),2};
            else if(a.c==1) return {(c==2),2};
            else if(a.c==2) return {(c==3),2};
            else if(a.c==4) return {(c==1),1};
        }
        else return {false,-1};
    }
    else if(a.d==4) // 右上
    {
        if(p==0) // 向左
        {
            if(a.c==3) return {(c==4),0};
            else if(a.c==1) return {(c==4),5};
            else if(a.c==2) return {(c==4),3};
            else if(a.c==4) return {(c==2),3};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==2),0};
            else if(a.c==1) return {(c==3),0};
            else if(a.c==2) return {(c==1),0};
            else if(a.c==4) return {(c==3),5};
        }
        else if(p==3) // 向上
        {
            if(a.c==3) return {(c==1),5};
            else if(a.c==1) return {(c==2),5};
            else if(a.c==2) return {(c==3),5};
            else if(a.c==4) return {(c==1),0};
        }
        else return {false,-1};
    }
    else if(a.d==5) // 右下
    {
        if(p==0) // 向左
        {
            if(a.c==3) return {(c==4),4};
            else if(a.c==1) return {(c==4),1};
            else if(a.c==2) return {(c==4),2};
            else if(a.c==4) return {(c==2),2};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==1),1};
            else if(a.c==1) return {(c==2),1};
            else if(a.c==2) return {(c==3),1};
            else if(a.c==4) return {(c==1),4};
        }
        else if(p==2) // 下
        {
            if(a.c==3) return {(c==2),4};
            else if(a.c==1) return {(c==3),4};
            else if(a.c==2) return {(c==1),4};
            else if(a.c==4) return {(c==3),1};
        }
        else return {false,-1};
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i*2-1;j++)
        {
            cin>>box[i][j];
        }
    }
    int ex,ey;
    cin>>ex>>ey;
    if(ex==1&&ey==1)
    {
        cout<<0;
        return 0;
    }
    memset(vis,false,sizeof(vis));
    memset(step,-1,sizeof(step));
    queue<Node>q;
    vis[1][1][0]=true;
    step[1][1][0]=0;
    q.push({1,1,4,0});
    while(!q.empty())
    {
        Node f=q.front();
        q.pop();
        // vis[f.x][f.y][f.d]=true;
        if(f.x==ex&&f.y==ey) break;
        vector<int>vec;
        vec.push_back(0);
        vec.push_back(1);
        if(f.y%2==1) vec.push_back(2);
        else vec.push_back(3);
        for(auto i:vec)
        {
            int nx=f.x+xx[i];
            int ny=f.y+yy[i];
            auto it=jud(f,i,box[nx][ny]);
            if(!vis[nx][ny][it.second]&&nx>=1&&nx<=n&&ny>=1&&ny<=2*nx-1)
            {
                if(it.first)
                {
                    int nd=it.second;
                    int nc=box[nx][ny];
                    vis[nx][ny][nd]=true;
                    q.push({nx,ny,nc,nd});
                    step[nx][ny][nd]=step[f.x][f.y][f.d]+1;
                }
            }
        }
    }
    int minans=INT_MAX;
    for(int i=0;i<10;i++) 
    {
        if(step[ex][ey][i]!=-1) 
        {
            minans=min(minans,step[ex][ey][i]);
        }
    }
    if(minans!=INT_MAX) cout<<minans;
    else cout<<-1;
}