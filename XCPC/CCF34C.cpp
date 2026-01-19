#include<bits/stdc++.h>
using namespace std;
const int N=5100;
struct Node 
{
	int x,y;
	int idx;
};
bool cmp(const Node &i,const Node &j)
{
	if(i.x!=j.x) return i.x<j.x;
	else return i.y<j.y;
}
bool vis[N];
vector<Node>a;
struct Item
{
	int idx;
	int len;	
};
bool cmp2(const Item &i,const Item &j)
{
	return i.len<j.len;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>g[n+1];
	int len[n+1][n+1];
	
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			len[i][j]=INT_MAX;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a.push_back({x,y,i});
	}
	sort(a.begin(),a.end(),cmp);
	while(m--)
	{
		int x,y,r,t;
		cin>>x>>y>>r>>t;
		Node n1={x-r,0,0};
		Node n2={x+r,0,0};
		int b=0;
		int e=n-1;
		vector<Node> vec;
		for(int i=b;i<=e;i++)
		{
			if(a[i].y>=y-r&&a[i].y<=y+r && a[i].x>=x-r&& a[i].x<=x+r)
			{
				vec.push_back(a[i]);
			}
		}
		for(int i=0;i<vec.size();i++)
		{
			for(int j=i+1;j<vec.size();j++)
			{
				int idi=vec[i].idx;
				int idj=vec[j].idx;
				g[idi].push_back(idj);
				g[idj].push_back(idi);
				len[idi][idj]=min(len[idi][idj],t);
				len[idj][idi]=min(len[idj][idi],t);
			}
		}
	}
    int dist[n+1];
    for(int i=1;i<=n;i++) dist[i]=INT_MAX;
    dist[1]=0;
    priority_queue<Item,vector<Item>,function<bool(Item,Item)>> pq(cmp2);
    pq.push({1,0});
    
    while(!pq.empty())
    {
        Item f=pq.top();
        pq.pop();
        int u=f.idx;
        if(vis[u]) continue;
        vis[u]=true;
        for(int v:g[u])
        {
            if(!vis[v] && dist[u]+len[u][v]<dist[v])
            {
                dist[v]=dist[u]+len[u][v];
                pq.push({v,dist[v]});
            }
        }
    }
    
    if(dist[n]==INT_MAX) cout<<-1<<endl;
    else cout<<dist[n]<<endl;

	return 0;
}