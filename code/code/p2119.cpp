#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m+1];
    int cnt[n+1]={0};
    int ansA[n+1]={0},ansB[n+1]={0},ansC[n+1]={0},ansD[n+1]={0};
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int t=1;t<=n/9;t++)
    {
        int sum=0;
        for(int D=1;D<=n;D++)
        {
            int A=D-9*t-1;
            int B=D-7*t-1;
            int C=D-t;
            if(A<=0) continue;
            sum+=cnt[A]*cnt[B];
            ansD[D]+=sum*cnt[C];
            ansC[C]+=sum*cnt[D];
        }
        sum=0;
        for(int A=n-9*t-1;A>=1;A--)
        {
            int B=A+2*t;
            int C=B+6*t+1;
            int D=C+t;
            sum+=cnt[C]*cnt[D];
            ansA[A]+=sum*cnt[B];
            ansB[B]+=sum*cnt[A];
        }
    }

    for(int i=0;i<m;i++)
    {
        cout<<ansA[a[i]]<<" "<<ansB[a[i]]<<" "<<ansC[a[i]]<<" "<<ansD[a[i]]<<"\n";
    }
}