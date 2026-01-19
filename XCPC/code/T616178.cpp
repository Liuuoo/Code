#include<bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    int idx;
};
int main()
{
    int n,p;
    cin>>n>>p; //2*n same level of p
    int ans=1;
    stack<Node>S;
    if(p!=1)
    {
        for(int i=1;i<=2*n;i++)
        {
            cout<<"?"<<" "<<i<<" "<<i;
            cout<<endl;
            cout.flush();
            int x;
            cin>>x;
            if(!S.empty()&&S.top().data==x)
            {
                if(S.top().idx==p)
                {
                    cout<<"!"<<" "<<i;
                    return 0;
                }
                else if(i==p)
                {
                    cout<<"!"<<" "<<S.top().idx;
                    return 0;
                }
                else S.pop();
            }
            else S.push({x,i});
        }
    }
    else 
    {
        bool flag=false;
        for(int i=2;i<=2*n-1;i++)
        {
            cout<<"?"<<" "<<i<<" "<<i;
            cout<<endl;
            cout.flush();
            int x;
            cin>>x;
            if(S.empty()&&x==1)
            {
                if(p==1) 
                {
                    cout<<"!"<<" "<<i;
                    return 0;
                }
                else 
                {
                    S.pop();
                }
            }
            else if(S.empty()&&i!=p)
            {

            }
            else if(!S.empty()&&S.top().data==x)
            {
                S.pop();
            }
            else S.push({x,i});
        }
        cout<<"!"<<" "<<2*n;
    }
}