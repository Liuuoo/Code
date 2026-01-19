#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool vis[N];
int A[N];
int t = 1, n;
int s[N];
int arr[500][500];
int tot[500];
int pairs;

int solve1()
{
    int ans=0;
    for(int i=1;i<=n;i++) vis[i]=false;
    int a[n+1];
    int b[n+1];
    vector<int> C;
    for(int i=n;i>=1;i--) C.push_back(A[i]);
    int c;
    for(int i=1;i<=n/2;i++) a[i]=C.back(), C.pop_back();
    if(n%2!=0) C.pop_back();
    for(int i=1;i<=n/2;i++) b[i]=C.back(), C.pop_back();
    reverse(b+1,b+(n/2+1));
    map<int,int> M1,M2;
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]==b[i])
        {
            vis[i]=true;
            continue;
        }
        M1[a[i]]++;
        M1[b[i]]++;
    }
    int maxCnt1=0;
    int maxVal1=INT_MIN;
    for(auto x:M1)
    {
        if(x.second>maxCnt1)
        {
            maxCnt1=x.second;
            maxVal1=x.first;
        }
    }
    for(int i=1;i<=n/2;i++)
    {
        if(!vis[i]&&a[i]!=maxVal1&&b[i]!=maxVal1)
        {
            M2[a[i]]++;
            M2[b[i]]++;
        }
    }
    int maxCnt2=0;
    int maxVal2=INT_MIN;
    for(auto x:M2)
    {
        if(x.second>maxCnt2)
        {
            maxCnt2=x.second;
            maxVal2=x.first;
        }
    }
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]==maxVal1||a[i]==maxVal2||b[i]==maxVal1||b[i]==maxVal2)
            {
                ans+=1;
            }
            else ans+=2;
        }
    }
    return ans;
}

int solve2()
{
    for (int i = 0; i < n; i++)
    {
        s[i]=A[i+1];
        s[i] += 200;
    }
    pairs = 0;
    for (int i = 0; i <= 400; i++)
    {
        tot[i] = 0;
        for (int j = i + 1; j <= 400; j++)
            arr[i][j] = 0;
    }
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            pairs++, tot[s[i]]++, tot[s[n - 1 - i]]++, arr[min(s[i], s[n - 1 - i])][max(s[i], s[n - 1 - i])]++;
    int res = pairs * 2;
    for (int i = 0; i <= 400; i++)
        for (int j = i + 1; j <= 400; j++)
        {
            int tmp = tot[i] + tot[j] - arr[i][j];
            res = min(res, tmp + (pairs - tmp) * 2);
        }
    return res;
}

int main()
{
    int T=1000000;
    srand(time(0));
    while(T--)
    {
        n=rand()%101+1;
        for(int i=1;i<=n;i++) A[i]=(rand()%200+1)*pow(-1,rand()%2);
        if(solve1()!=solve2())
        {
            cout<<n<<'\n';
            for(int i=1;i<=n;i++) cout<<A[i]<<" ";
            cout<<'\n';
            cout<<solve1()<<" "<<solve2()<<endl;
            return 0;
        }
    }
}
// 33
// -92 -48 -120 -124 46 78 -36 -72 141 -63 13 -152 94 -2 50 12 65 -160 -30 32 13 32 -152 -180 171 -91 140 -44 -95 48 -64 185 -58 
// 29 28