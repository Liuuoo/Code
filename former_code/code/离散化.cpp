#include<bits/stdc++.h>
using namespace std;
struct D
{
	bool operator()(int a,int b)
	{
		return a>b;
	} 
};
set<int,D>W;
priority_queue<int,vector<int>,D>q;
struct Dis
{
	vector<int>a; 
	Dis(vector<int>_a)
	{
		a=_a;
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end()); 
	}
	int find(int x)
	{
		return lower_bound(a.begin(),a.end(),x)-a.begin();
	}	//from 0
};
struct Map
{
	map<int,int>S;
	int sz;
	Map()
	{
		sz=0;
	}	
	void insert(int x)
	{
		sz++;
		S[x]++; 
	}
	void erase(int x)
	{
		sz--;
		S[x]--;
		if(S[x]==0)
		{
			S.erase(x);
		}
	}
	int max()
	{
		if(sz==0)
		{
			return -1;
		}
		return S.begin()->first;
	} 
		int min()
		{
		if(sz==0)return -1;
		return S.rbegin()->first;
		}
};

struct Hash
{
	const int base=131;
	const int mod=1e9+7; 
	string s;
	vector<int>H;
	vector<int>B;
	Hash (string _s)
	{
		s=" "+_s;
		H.resize(s.size());
		B.resize(s.size());
		B[0]=1;
		for(int i=1;i<s.size();i++)
		
		B[i]=B[i-1]*base%mod;
		
		for(int i=1;i<s.size();i++)
		{
			H[i]=H[i-1]*base%mod+s[i];
			H[i]%=mod; 
		} 
	}	
	int get(int l,int r)
	{
		l++;
		r++;
		return ((H[r]-H[l-1]*B[r-l+1]%mod)%mod+mod)%mod; 
	 } 
};


void f(string s)
{
	s="abc";
}
signed main()
{
	string s="123";
	f(s);
	cout<<s<<"\n"; 
	return 0;
}
