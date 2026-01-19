#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r,L,R,K;
// string ss="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// set<string>S[50];
// string s;
map<int,int>ans;

// int calc(int bit,string &s,int len)
// {
//     int num=0,c=0;
//     for(int i=len-1;i>=0;i--)
//     {
//         int tn;
//         if(isdigit(s[i]))
//         {
//             tn=s[i]-'0';
//         }
//         else tn=s[i]-'A'+10;
//         num+=tn*pow(bit,c);
//         c++;
//     }
//     return num;
// }

// void dfs(int x,int bit,char a,char b)
// {
//     if(s!="")
//     {
//         int num=calc(bit,s,x);
//         if(num>=L&&num<=R) 
//         {
//             S[bit].insert(s);
//             ans[num]++;
//         }
//         if(num>=R) return; 
//     }
//     s+=a;
//     s+=b;
//     dfs(x+2,bit,a,b);
// }

signed main()
{
    cin>>l>>r>>L>>R>>K;
    for(int i=l;i<=r;i++)
    {
        for(int j=1;j<i;j++)
        {
            // string tmp;
            // tmp+=ss[j];
            // int num=calc(i,tmp,1);
            // if(num>=L&&num<=R) ans[num]++;
            for(int k=0;k<i;k++)
            {
                int tmp=0;
                if(j!=k) 
                {
                    for(int l=0;tmp<=R;l++)
                    {
                        if(l%2==0)
                        {
                            tmp=tmp*i+j;
                        }
                        else 
                        {
                            tmp=tmp*i+k;
                        }
                        if(tmp>=L&&tmp<=R) ans[tmp]++;
                    }
                    // s="";
                    // dfs(0,i,ss[j],ss[k]);

                }
            }
        }
    }
    for(auto x:ans)
    {
        if(x.second==K)
        {
            cout<<x.first<<'\n';
        }
    }
}