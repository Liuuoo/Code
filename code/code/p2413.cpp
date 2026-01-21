#include<bits/stdc++.h>
using namespace std;
double p[27];
string ss;
double calcc(vector<double> vec)                                                                    
{
    double tmp=1;
    for(auto x:vec) tmp*=(1-x);
    return 1.0-tmp;
}
double calcb(vector<double> vec)
{
    double res=1.0;
    for(auto x:vec) res*=x;
    return res;
}
double dfs(int l,int r)
{
    // cout<<l<<" "<<r<<'\n';
    if(l==r) 
    {
        return p[ss[l]-'A'];
    }
    if(ss[l]=='(') //说明当前区间有并联,处理所有同级并联
    {
        vector<double> vecb,vecc;
        double L,R;
        int i=l;
        int cnt=0;
        while(i<=r)
        {
            int j=i;
            while(j<=r)
            {
                if(ss[j]=='(') cnt++;
                if(ss[j]==')') cnt--;
                if(cnt==0)
                {
                    double tmp=dfs(i+1,j-1);
                    vecb.push_back(tmp);
                    break;
                }
                j++;
            }
            j++;
            if(j>r) break; //末尾
            if(ss[j]!='(') //认为后续串联直接结束
            {
                j++;
                R=dfs(j,r);
                break;
            }
            else //认为同级并联
            {
                i=j;
                cnt=0;
            }
        }
        L=calcb(vecb);
        vector<double> tttt;
        tttt.push_back(L);
        tttt.push_back(R);
        return calcc(tttt);
    }
    else //以,分割且一定同级
    {
        vector<double>vec;
        vec.push_back(dfs(l,l));
        vec.push_back(dfs(l+2,r));
        return calcc(vec);
    }
}
int main()
{
    int n;  cin>>n;
    cin>>ss;
    for(int i=0;i<n;i++) cin>>p[i];
    printf("%.4f",dfs(0,ss.size()-1));
}
