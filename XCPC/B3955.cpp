#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int n=(a+1)/2;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(j==1||j==a) cout<<'|';
			else if(i==1||i==n||i==a) cout<<'-';
            else cout<<'x';
		}
		cout<<'\n';
	}
	return 0;
}