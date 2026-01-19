#include<bits/stdc++.h>
using namespace std;
int box[23][23];
int n;

pair<int,int>jud1(pair<int,int>p)
{
    int x=p.first;
    int y=p.second;
    x=(x-1+n)%n;
    y=(y+1)%n;
    if(box[x][y]) 
    {
        return {-1,-1};
    }
    else return {x,y};
}

pair<int,int>jud2(pair<int,int>p)
{
    int x=p.first;
    int y=p.second;
    x=(x+1)%n;
    return {x,y};
}

int main()
{
    cin>>n;
    int i=0,j=n/2;
    pair<int,int> p={i,j};
    box[i][j]=1;
    int cnt=2;
    while(1)
    {
        pair<int,int> np=jud1(p);
        if(np!=(pair<int,int>){-1,-1})
        {
            box[np.first][np.second]=cnt++;
            p=np;
        }
        else 
        {
            pair<int,int> np=jud2(p);
            box[np.first][np.second]=cnt++;
            p=np;
        }
        if(cnt>n*n) break;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<box[i][j]<<" ";
        }
        cout<<'\n';
    }
}