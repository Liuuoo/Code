#include<bits/stdc++.h>
using namespace std;
#define int long long
int bac_sum[9999];
signed main()
{
    string s;
    for(int i=1;i<=2023;i++)
    {
        string tmp=to_string(i);
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]=='2'||tmp[i]=='0'||tmp[i]=='3')
            {
                s+=tmp[i];
            }
        }
    }

    for(int i=s.size()-1;i>=0;i--)
    {
        bac_sum[i]=bac_sum[i+1]+(s[i]=='3');
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='2')
        {
            for(int j=i+1;j<s.size();j++)
            {
                if(s[j]=='0')
                {
                    for(int k=j+1;k<s.size();k++)
                    {
                        if(s[k]=='2')
                        {
                            for(int l=k+1;l<s.size();l++)
                            {
                                if(s[l]=='3')
                                {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    // cout<<"1189693313";
}