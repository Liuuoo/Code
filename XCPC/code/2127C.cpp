#include<bits/stdc++.h>
using namespace std;
#define int long long
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
		return S.rbegin()->first;
	} 
    int min()
    {
        if(sz==0)return -1;
        return S.begin()->first;
    }
};
struct Node
{
    int val;
    int index;
};
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    Map MX,MI;
    // map<int,int>MX;
    // map<int,int>Mi;
    for(int i=0;i<n;i++)
    {
        // MX[a[i]]++;
        // Mi[b[i]]++;
        MX.insert(max(a[i],b[i]));
        MI.insert(min(a[i],b[i]));
    }
    bool jud=false;
    for(int i=0;i<n;i++)
    {
        int A=a[i];
        int B=b[i];
        // MX[max(A,B)]--;
        // Mi[min(A,B)]--;
        MX.erase(max(A,B));
        MI.erase(min(A,B));
        if(min(A,B)>MX.min())
        {
            jud=true;
        }
        // MX[max(A,B)]++;
        // Mi[min(A,B)]++;
        MX.insert(max(A,B));
        MI.insert(min(A,B));
    }
    if(n==2)
    {
        int x[]={a[0],b[0],a[1],b[1]};
        sort(x,x+4);
        cout<<x[3]+x[2]-x[1]-x[0]<<'\n';
    }
    else if(!jud)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(a[i]-b[i]);
        }
        cout<<ans<<'\n';
    }
    else 
    {
        vector<Node>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({a[i]+b[i],i});
        }
        sort(vec.begin(),vec.end(),[](Node x,Node y){
            return x.val<y.val;
        });
        int minn=INT64_MAX;
        int indexA,indexB;
        for(int i=0;i<n-1;i++)
        {
            if(minn>vec[i+1].val-vec[i].val)
            {
                minn=vec[i+1].val-vec[i].val;
                indexA=vec[i].index;
                indexB=vec[i+1].index;
            }
        }
        swap(a[indexA],b[indexB]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(a[i]-b[i]);
        }
        cout<<ans<<'\n';
    }
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}