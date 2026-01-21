#include<bits/stdc++.h>
using namespace std;

int lcm(int a,int b,int c)
{
    int g1=__gcd(a,b);
    int l1=a*b/g1;
    int g2=__gcd(l1,c);
    int l2=l1*c/g2;
    return l2;
}
bool vaild(int x)
{
    return (x>=100&&x<=999);
}
bool jud(int a,int b,int c)
{
    bool vis[10]={false};
    string s=to_string(a)+to_string(b)+to_string(c);
    for(auto x:s)
    {
        if(!isdigit(x)||vis[x-'0']||x=='0') return false;
        vis[x-'0']=true;
    }
    return true;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==0||b==0||c==0)
    {
        cout<<"No!!!";
        return 0;
    }
    int d=lcm(a,b,c);
    bool flag=false;
    for(int i=0;;i++)
    {
        int A=i/d*a;
        int B=i/d*b;
        int C=i/d*c;
        if(i%d==0)
        {
            if(vaild(A)&&vaild(B)&&vaild(C)&&jud(A,B,C))
            {
                cout<<A<<" "<<B<<" "<<C<<'\n';
                flag=true;
            }
        }
        if(A>999&&B>999&C>999) break;
    }
    if(!flag) cout<<"No!!!";
}