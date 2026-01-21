#include <bits/stdc++.h>//有亿点点长
using namespace std;
int x,y,a,b = 1,c,d = 1;
int z(int n)
{
	int sum = 1 , ans = 1;
	while(n != 0)
	{
		sum = sum * n % 10 * ans;
		ans *= 10;
		n /= 10;
	}
	return sum;
}
int main()
{
	char mm = 'h'; 
	string s;
	cin >> s;
	int j = s.find('=') , k;
	for(int i = 0; i < s.size(); i++)
	{		
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			a = 0;
			mm = s[i];
			b = 1;
			k = i-1;
			while(s[k] <= '0' && s[k] <= 9)
			{
				//cout<<'1'<<endl;
				if(s[k] >= '0' && s[k] <= '9')
				{
					a = int(s[k] - '0') * b;
					b *= 10;
				}
				k--;
			}
			a = z(a);
			if(s[k] == '+')
			{
				if(i < j)
				{
					x += a;
				}
				else
				{
					x -= a;
				}
			}
			if(s[k] == '-')
			{
				if(i < j)
				{
					x -= a;
				}
				else
				{
					x += a;
				}
			}
		}
		else
		{
			if(s[i] >= '0' && s[i] <= '9')
			{
				c = 0;
				d = 1;
				k = i-1;
				while(s[k] >= '0' && s[k] <= '9')
				{	
					//cout << 1 << endl;
					c = int(s[k] - '0') * d;
					d *= 10;
					k++;
				}
				c = z(c);
				if(s[k] == '+')
				{
					if(i < j)
					{
						y -= c;
					}
					else
					{
						y += c;
					}
				}
				if(s[k] == '-')
				{
					if(i < j)
					{
						y += c;
					}
					else
					{
						y -= c;
					}
				}				
			}
		}
		cout << x << " " << y << endl;
	}
	cout << x << " " << y << endl;
	cout << mm << '=';
	printf("%.3lf",double(y) / x);
	return 0;
}
