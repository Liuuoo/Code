#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    if(isalpha(s[0]))
    {
        s[0]=toupper(s[0]);
    }
    for(int i=1;i<s.size();i++)
    {
        s[i]=tolower(s[i]);
    }
    cout<<s<<'\n';
}

int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		solve();
	} 
	return 0;
}

