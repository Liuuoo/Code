#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,m1,n2,m2;
    cin>>n1>>m1;
    int box1[n1+1][m1+1];
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=m1;j++)
        {
            cin>>box1[i][j];
        }
    }
    cin>>n2>>m2;
    int box2[n2+1][m2+1];
    for(int i=1;i<=n2;i++)
    {
        for(int j=1;j<=m2;j++)
        {
            cin>>box2[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=m1;j++)
        {
            for(int k=i;k<=n1;k++)
            {
                for(int l=j;l<=m1;l++)
                {
                    for(int m=1;m<=n2;m++)
                    {
                        for(int n=1;n<=m2;n++)
                        {
                            int xl=k-i+1,yl=l-j+1;
                            bool jud=false;
                            for(int x=0;x<xl;x++)
                            {
                                for(int y=0;y<yl;y++)
                                {
                                    if(box1[i+x][j+y]!=box2[m+x][n+y])
                                    {
                                        jud=true;
                                        break;
                                    }
                                }
                            }
                            if(!jud)
                            {
                                ans=max(ans,xl*yl);
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;

}