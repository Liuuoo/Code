#include<bits/stdc++.h>
#include <functional>
using namespace std;
#define int long long
using i128 = __int128_t;
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
 
const i128 mod=1e9+7;
i128 dfs(i128 has,i128 even,i128 odd,i128 player,i128 len)
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
signed main()
{
    int l,r;
    cin>>l>>r;
    //cout<<dfs(4,2,1,1,1)<<"\n";
    int t=(((dfs(r,2,1,1,1)-dfs(l-1,2,1,1,1))%mod+mod)%mod);
    cout<<t<<"\n";
}