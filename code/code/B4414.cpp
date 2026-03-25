#include<bits/stdc++.h>
using namespace std;
int day[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int sp=2;
    string s="MON TUE WED THU FRI SAT SUN\n";
    int n;
    cin>>n;
    int d=day[n];
    for(int i=2;i<=n;i++)
    {
        sp=(day[i-1]+sp)%7;
    }
    cout<<s;
    int t=1;
    for(int i=1;i<=sp+day[n];i++)
    {
        if(i<=sp) cout<<"    ";
        else
        {
            printf("%3d ",t++);
        }
        if(i%7==0) cout<<'\n';
    }
}