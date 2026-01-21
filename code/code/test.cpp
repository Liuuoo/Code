#include <bits/stdc++.h>
using namespace std;
void arr(int *b,int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
	}
}

void solve()
{
	int n;
	cin>>n;
	int a[n+1];
	int mx=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	bool cnt[mx+1]={0};
	set<int>S;
	for(int i=1;i<=n;i++)
	{
		if(S.find(a[i])!=S.end())
		{
			
		}
		else 
		{
			cout<<a[i]<<" ";
			S.insert(a[i]);
		}
	}
	cout<<'\n';
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
}

