#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define For(i,x,y) for(ll i=x;i<=y;++i)
#define Rof(i,x,y) for(ll i=x;i>=y;--i)

const int N = 2e5+5;

int n;
int a[N];
ll s[N];
vector<ll> all;
unordered_map<ll,bool> mp;
bool solve(ll x){
	for(ll i=x;i<=s[n];i+=x){
		if(mp.count(i)==0) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	For(i,1,n){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		mp[s[i]]=1;
	}
	For(i,1,n){

		if(solve(s[i])){
			cout<<s[i]<<'\n';
			return 0;
		}
	}
	
	return 0;
}