#include<bits/stdc++.h>
using namespace std;
// 0左 1右 2下
int xx[]={0,0,1,-1};
int yy[]={-1,1,1,-1};

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
            else if(a.c==3) return {(c==4),1};
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
            else if(a.c==4) return {(c==1),2};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==4),0};
            else if(a.c==1) return {(c==4),0};
            else if(a.c==2) return {(c==4),0};
            else if(a.c==4) return {(c==2),5};
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
            if(a.c==3) return {(c==2),1};
            else if(a.c==1) return {(c==3),1};
            else if(a.c==2) return {(c==1),1};
            else if(a.c==4) return {(c==3),2};
        }
        else if(p==1) //向右
        {
            if(a.c==3) return {(c==4),2};
            else if(a.c==1) return {(c==4),2};
            else if(a.c==2) return {(c==4),4};
            else if(a.c==4) return {(c==2),4};
        }
        else if(p==2)
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

void solve()
{
    int box[105][255];
    map<pair<int,int>,bool>vis;
    int n;
    // cin>>n;
    n=rand()%100+2;
    map<pair<int,int>,int>step;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i*2-1;j++)
        {
            // cin>>box[i][j];
            box[i][j]=rand()%4+1;
            // cout<<box[i][j]<<' ';
        }
        // cout<<'\n';
    }
    int ex,ey;
    // cin>>ex>>ey;
    ex=rand()%n+1;
    ey=rand()%(ex*2-1)+1;
    if(ex==1&&ey==1)
    {
        cout<<0<<'\n';
        return;
    }
    queue<Node>q;
    vis[{1,1}]=true;
    q.push({1,1,4,0});
    while(!q.empty())
    {
        Node f=q.front();
        q.pop();
        vis[{f.x,f.y}]=true;
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
            if(nx>=1&&nx<=n&&ny>=1&&ny<=2*nx-1&&!vis[{nx,ny}])
            {
                auto it=jud(f,i,box[nx][ny]);
                if(it.first)
                {
                    int nd=it.second;
                    int nc=box[nx][ny];
                    q.push({nx,ny,nc,nd});
                    step[{nx,ny}]=step[{f.x,f.y}]+1;
                }
            }
        }
    }
    if(step[{ex,ey}]==0)
    {
        cout<<-1<<'\n';
    }
    else cout<<step[{ex,ey}]<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int T=1000000000000000000;
    while(T--)
    {
        solve();
    }
}