#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    int flag=n/3;
    int cnt[3]={0};
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        vec.push_back(c-'0');
        cnt[c-'0']++;
    }
    int tmp[3]={0};
    for(int i=0;i<n;i++)
    {
        int x=vec[i];
        if(cnt[x]==flag) 
        {
            tmp[x]++;
            continue;
        }
        if(cnt[x]>flag)
        {
            for(int j=0;j<3;j++)
            {
                if(cnt[j]<flag)
                {
                    if(j<x)
                    {
                        cnt[j]++;
                        tmp[j]++;
                        cnt[x]--;
                        vec[i]=j;
                    }
                    else 
                    {
                        if(tmp[x]==flag)
                        {
                            cnt[j]++;
                            cnt[x]--;
                            vec[i]=j;
                            break;
                        }
                        else 
                        {
                            tmp[x]++;
                        }
                    }
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<vec[i];
    }
}