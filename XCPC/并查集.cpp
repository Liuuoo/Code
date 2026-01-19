#include<bits/stdc++.h>
using namespace std;
struct UF
{
	vector<int>fa;
	UF(int n)
	{
		fa.resize(n+10);
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
	}
	int find(int x)
	{
		if(x==fa[x])
		return x;
		return fa[x]=find(fa[x]);
	}
	void unity(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b)
		{
			return;
		}
		else fa[a]=b;
	 } 
};
signed main()
{
	int n,m;
	cin>>n>>m;
	UF uf(n);
	 while(m--)
	 {
	 	int a,b,c;
	 	cin>>a>>b>>c;
	 	if(a==1)
	 	{
	 		uf.unity(b,c);
		 }
		 else 
		 {
		 	if(uf.find(b)==uf.find(c))
		 	{
		 		cout<<"Y\n";
			 }
			 else cout<<"N\n";
		 }
	  } 
}
//const int N=2e5+10;
//int fa[N];
//
//int find(int x)
//{
//	if(fa[x]==x) return x;
//	else return fa[x]=find(fa[x]); 
//}
//
//void unity(int x, int y)
//{
//
//	int a=find(x);
//	int b=find(y);
//	if(a==b)return;
//	
//	fa[a]=b;
//}
//
//int main()
//{
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++) fa[i]=i;
//	while(m--)
//	{
//		int z,x,y;
//		cin>>z>>x>>y;
//		if(z==1)
//		{
//			//assert(x!=y);
//			//if(find(x)!=find(y))
//			unity(x,y);
//		}
//		else if(z==2)
//		{
////			cout<<find(x)<<" "<<find(y)<<"\n";
////			assert((find(x)>=1)&&(find(x)<=n));
////			assert((find(y)>=1)&&(find(y)<=n));
////			assert() 
//			if(fa[find(x)]==fa[find(y)])
//			{
//				cout<<"Y\n";
//			}
//			else cout<<"N\n";
//		}
//	}
//}  
