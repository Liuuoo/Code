#include<bits/stdc++.h>
using namespace std;
string s="$ABCDEFGHI";
int n,m;
const int N=110;
int box[N][N];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
#define ll long long
ll a[N][N];
const ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int fid(int x,int y) 
{
    bool vis[27]={false};
    for(int i=0;i<4;i++)
    {
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx<1||ny<1||nx>n||ny>m) continue;
        int c=box[nx][ny];
        if(c) 
        {
            vis[c]=true;
        }
    }
    for(int i=1;i<=26;i++)
    {
        if(!vis[i]) return i;
    }
}

void draw(int x,int y)
{
    int nx=x,ny=y;
    int color=fid(x,y);
    while(nx<=n&&ny<=m)
    {   
        nx++;
        ny++;
        int R=fid(x,ny);
        int D=fid(nx,y);
        if(R!=color||D>color||box[x][ny]||box[nx][y]) 
        {
            break;
        }
    }
    nx--;
    ny--;
    for(int i=x;i<=nx;i++)
    {
        for(int j=y;j<=ny;j++)
            box[i][j]=color;
    }
}

ll check(ll x,ll y,ll z)//判断(x,y)上能不能填z
{
	for(ll i=0;i<=3;i++)
	{
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m)continue;
		if(a[xx][yy]==z)return 0;
	}
	return 1;
}

void solve2()
{
    ll i,j,k,l,p,q,x,y;
    for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i][j])continue;//填过了就跳过
			for(k=1;k<=4;k++)//枚举颜色
			{
				if(!check(i,j,k))continue;//不能填就跳过
				for(l=1;l<=200;l++)//枚举边长
				{
					x=i+l-1;y=j+l-1;//地砖右下角的坐标
					if(x>n||y>m||a[i][y]||a[x][j]||!check(i,y,k)||!check(x,j,k))break;
                    //不符合以上条件就退出扩展
					bool flag=0;
					for(p=1;p<=k-1;p++)
						if(check(i,y,p))
						{
							flag=1;
							break;
						}//可以填字典序更小的颜色就退出扩展
					if(flag)break;
				}
				for(p=i;p<=x-1;p++)
					for(q=j;q<=y-1;q++)
						a[p][q]=k;//铺地砖
				break;
			}
		}
}

void solve1()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(box[i][j]) continue;
            draw(i,j);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         int c=box[i][j];
    //         cout<<s[c];
    //     }
    //     cout<<'\n';
    // }
}

void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<s[box[i][j]];
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<s[a[i][j]];
        }
        cout<<'\n';
    }
}

int main()
{
    srand(time(0));
    while(1)
    {
        memset(a,0,sizeof(a));
        memset(box,0,sizeof(box));
        n=rand()%13+1;
        m=rand()%12+1;
        // n=10,m=12;
        solve1();
        solve2();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(box[i][j]!=a[i][j])
                {
                    cout<<n<<" "<<m<<'\n';
                    print();
                    return 0;
                }
            }
        }
    }
    
}