#include<bits/stdc++.h>
using namespace std;
#define int long long 
// const int mod=1e9+7;
vector<int>vec;
using i64 = __int128_t;
i64 abs(const i64 &x)
{
    return x>0?x:-x;
}
auto &operator>>(istream &it,i64 &j)
{
    string val;
    it>>val;
    reverse(val.begin(),val.end());
    i64 ans=0;
    bool f=0;
    char c=val.back();
    val.pop_back();
    for(;c<'0'||c>'9';c=val.back(),val.pop_back())
    {
        if(c=='-') f=1;
    }
    for(;c>='0'&&c<='9';c=val.back(),val.pop_back())
    {
        ans=ans*10+c-'0';
    }
    j=f? -ans:ans;
    return it;
}
ostream &operator<<(ostream &os,i64 &j)
{
    string ans;
    function<void(i64)> write=[&](i64 x)
    {
        if(x<0) ans+='-',x=-x;
        if(x>9) write(x/10);
        ans+=x%10+'0';
    };
    write(j);
    return os<<ans;
}

const i64 mod=1e9+7;
i64 dfs(i64 has,i64 even,i64 odd,i64 player,i64 len)
{
    // even%=mod;
    // odd%=mod;
    // if(even<0)even+=mod;
    // if(odd<0)odd+=mod;
    // assert(odd>0);
    // assert(even>0);
    if(has==0)
        return 0;
    if(player==0)
    {

        if(len >= has)
        {
            return ((even+even+has*2-2)*has/2)%mod;
        }
        else 
        {
            return (((even+even+len*2-2)*len/2)%mod+dfs(has-len,even+len*2,odd,player^1,len*2))%mod;
        }
    }
    else{
         if(len >=has)
        {
            return ((odd+odd+has*2-2)*has/2)%mod;
        }
        else 
        {

            return (((odd+odd+len*2-2)*len/2)%mod+dfs(has-len,even,odd+len*2,player^1,len*2))%mod;
        }
    }
}
//1+2+4+3

int solve2(int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=vec[i];
        sum%=mod;
    }
    return sum;
}

signed main()
{
    vec.push_back(0);
    int cnt=1;
    int e=1,o=2;
    while(vec.size()<=1000000)
    {
        for(int j=0;j<cnt;j++) 
        {
            vec.push_back(e);
            e+=2;
        }
        cnt=(cnt<<1);
        for(int j=0;j<cnt;j++)
        {
            vec.push_back(o);
            o+=2;
        }
        cnt=(cnt<<1);
    }
    // for(int i=1;i<=100;i++) cout<<vec[i]<<" ";
    int T=100200;
    srand(time(0));
    while(T--)
    {
        int l,r;
        l=rand()%100000+1;
        r=rand()%800000+l;
        //cout<<dfs(4,2,1,1,1)<<"\n";
        int ans1=((dfs((i64)r,2,1,1,1)-dfs((i64)l-1,2,1,1,1))%mod+mod)%mod;
        int ans2=solve2(l,r);
        cout<<ans1<<" "<<ans2<<'\n';
        if(ans1!=ans2)
        {
            cout<<l<<" "<<r<<" "<<ans1<<" "<<ans2<<"\n"; 
            return 0;
        }
    }
}