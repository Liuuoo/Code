#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec1,vec2;
    for(int i=0;i<4;i++)
    {
        int x; char c;
        cin>>x;
        if(i!=3) cin>>c;
        vec1.push_back(x);
    }
    for(int i=0;i<4;i++)
    {
        int x; char c;
        cin>>x;
        if(i!=3) cin>>c;
        vec2.push_back(x);
    }

    int t=1;
    while(1)
    {
        vec1[3]++;
        if(vec1[3]==100)
        {
            vec1[3]=0;
            vec1[2]++;
            if(vec1[2]==60)
            {
                vec1[2]=0;
                vec1[1]++;
                if(vec1[1]==60)
                {
                    vec1[1]=0;
                    vec1[0]++;
                    if(vec1[0]==24) vec1[0]=0;
                }
            }
        }
        if(vec1==vec2)
        {
            cout<<t;
            break;
        }
        t++;
    }
}
