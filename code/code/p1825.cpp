#include<bits/stdc++.h>
using namespace std;
const int N=1234;
char box[N][N];
map<char,pair<pair<int,int>,pair<int,int>>> ti;
queue<pair<int,int>> q;
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
int step[N][N]={0};
int vis[N][N]={0};

int main()
{
    int n,m;
    cin>>n>>m;
    pair<int,int>ed;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            box[i][j]=c;
            if(isalpha(c))
            {
                if(ti.find(c)==ti.end())
                    ti[c].first={i,j};
                
                else 
                    ti[c].second={i,j};
            }
            else if(c=='@')
            {
                q.push({i,j});
            }
            else if(c=='=')
            {
                ed={i,j};
            }
        }
    }

    // cout<<ed.first<< " "<<ed.second<<'\n';
    while(!q.empty())
    {
        pair<int,int> now_node=q.front();
        // cout<<now_node.first<<" "<<now_node.second<<"\n";
        if(now_node==ed) break;
        int now_x=now_node.first;
        int now_y=now_node.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int next_x=now_x+xx[i];
            int next_y=now_y+yy[i];
            if(next_x>=0&&next_y>=0&&next_x<n&&next_y<m)
            {
                if(isalpha(box[next_x][next_y]))
                {
                    if(vis[next_x][next_y]==0)
                    {
                        vis[next_x][next_y]++;
                        pair<int,int> p1=ti[box[next_x][next_y]].first;
                        pair<int,int> p2=ti[box[next_x][next_y]].second;
                        if(p1==(pair<int,int>){next_x,next_y})
                        {
                            q.push(p2);
                            step[p2.first][p2.second]=step[now_x][now_y]+1;
                        }
                        else 
                        {
                            q.push(p1);
                            step[p1.first][p1.second]=step[now_x][now_y]+1;
                        }
                    }
                }
                else 
                {
                    if(vis[next_x][next_y]==0&&(box[next_x][next_y]=='.'||box[next_x][next_y]=='='))
                    {
                        vis[next_x][next_y]++;
                        q.push({next_x,next_y});
                        step[next_x][next_y]=step[now_x][now_y]+1;
                    }
                }

            }
        }
    }
    cout<<step[ed.first][ed.second];
}