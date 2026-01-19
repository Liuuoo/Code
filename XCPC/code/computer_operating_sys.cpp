#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int time;
    int type; // 1-cpu 0-i/o
};

bool have_pc(vector<queue<Node>> &cmpt)
{
    for(int i=1;i<cmpt.size();i++)
    {
        if(!cmpt[i].empty()) return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<queue<Node>> cmpt(n+1);
    for(int i=1;i<=n;i++)
    {
        int m=3;
        for(int j=1;j<=3;j++) // 默认三个，顺序是CPU I/O CPU
        {
            int x;
            cin>>x;
            Node node={x,j%2};
            cmpt[i].push(node);
        }
    }
    int ioTime=0;
    int cpuTime=0;
    int indexIo=-1,indexCpu=-1;
    int ans=0;
    while(1)
    {
        // if(jud(cmpt)) break;
        for(int i=1;i<=n;i++)
        {
            if(cpuTime==0&&!cmpt[i].empty()&&cmpt[i].front().type==1) //找到可执行cpu
            {
                indexCpu=i;
                cpuTime=cmpt[i].front().time; //cpu时间
            }
            if(ioTime==0&&!cmpt[i].empty()&&cmpt[i].front().type==0) //找到可执行i/o
            {
                indexIo=i;
                ioTime=cmpt[i].front().time; //i/o时间
            }
            if(indexCpu!=-1&&indexIo!=-1) break;
        }
        if(indexIo==-1) // 未找到可执行io
        {
            cout << "未找到能运行的IO进程，执行进程" << indexCpu << "的CPU进程，用时" << cpuTime << endl;
            ans+=cpuTime;
            cpuTime=0;
            cmpt[indexCpu].pop();
            indexCpu=-1;
        } 
        else if(indexCpu==-1) // 未找到可执行cpu
        {
            cout << "未找到能运行的CPU进程，执行进程" << indexIo << "的IO进程，用时" << ioTime << endl;
            ans+=ioTime;
            ioTime=0;
            cmpt[indexIo].pop();
            indexIo=-1;
        }
        else if(cpuTime>ioTime) //ioTime先用完
        {
            cout << "并行执行中，IO进程（进程" << indexIo << "）先完成，用时" << ioTime << "；CPU进程（进程" << indexCpu << "）被挂起，剩余时间" << cpuTime-ioTime << endl;
            cpuTime-=ioTime;
            ans+=ioTime;
            ioTime=0;
            cmpt[indexIo].pop();
            indexIo=-1;
        }
        else if(cpuTime<ioTime) //cpuTime先用完
        {
            cout << "并行执行中，CPU进程（进程" << indexCpu << "）先完成，用时" << cpuTime << "；IO进程（进程" << indexIo << "）被挂起，剩余时间" << ioTime-cpuTime << endl;
            ioTime-=cpuTime;
            ans+=cpuTime;
            cpuTime=0;
            cmpt[indexCpu].pop();
            indexCpu=-1;
        }
        else //cpuTime==ioTime
        {
            cout << "并行执行中，CPU进程（进程" << indexCpu << "）与IO进程（进程" << indexIo << "）同时完成，用时" << cpuTime << endl;
            ans+=cpuTime;
            cpuTime=0;
            ioTime=0;
            cmpt[indexIo].pop();
            cmpt[indexCpu].pop();
            indexIo=-1;
            indexCpu=-1;
        }
        if(!have_pc(cmpt)) break;
    }
    cout<<ans;
}