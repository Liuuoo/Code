#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main()
{
    int k;
    string s;
    cin>>k>>s;
    int i=0;
    while(i<s.size())
    {
        int j=i;
        int cnt=1;
        while(j+1<(int)s.size()&&s[j]==s[j+1])
        {
            j++;
            cnt++;
            if(cnt>=k)
            {
                cout<<s[j];
                return 0;
            }
        }
        i=j+1;
    }
    cout<<"No";
}