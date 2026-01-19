#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e9+5;
vector<int>S;
using i128 = __int128_t;
typedef long long LL;

ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    S.push_back(1);
    int tab=1;
    while(tab<=N)
    {
        tab=tab*2;
        S.push_back(tab);
    }
    i128 sum=0;
    int n,x,y;
    cin>>n>>x>>y;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
    map<int,int>M;
    int cnt[n];
    int maxn=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1||a[i]==0) 
        {
            continue;
        }
        int pos=lower_bound(S.begin(),S.end(),a[i])-S.begin();
        if(S[pos]!=a[i]) pos--;
        M[pos]++;
        cnt[i]=pos;
        maxn=max(maxn,pos);
    }
    int _2=1;
    i128 ans=INT64_MAX;
    while(_2<=maxn)
    {
        i128 time=1ll<<_2;
        i128 tmp=0;
        for(int i=0;i<n;i++)
        {
            int st;
            if(a[i]==1||a[i]==0) 
            {
                st=0;
            }
            else if(a[i]<=time)
            {
                st=cnt[i];
            }
            else 
            {
                st=_2;
            }
            int _1=0;
            int ta=a[i];
            while(st--)
            {
                if(ta&1) 
                {
                    _1++;
                }
                ta>>=1;
            }
            tmp+=(ta+_1)*x;
        }
        tmp+=y*_2;
        ans=min(ans,tmp);
        _2++;
    }
    cout<<min(ans,sum*(i128)x)<<endl;
}