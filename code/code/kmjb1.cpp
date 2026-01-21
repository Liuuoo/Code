#include<bits/stdc++.h>
using namespace std;

int n;
const int N=2e5+10;
map<int,vector<int>> g;
map<int,bool> vis;
int ans=0;

void dfs(int x)
{
	ans=max(ans,x);
	vis[x]=true;
	for(auto y:g[x])
	{
		if(!vis[y])
		{
			dfs(y);
		}
	}
}

int main()
{
	cin>>n;

	for(int i = 1 ; i <= n ; ++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout<<ans;
	return 0;
}