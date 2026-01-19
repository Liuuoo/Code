#include<bits/stdc++.h>
using namespace std;
int p;
struct Node
{
    int x,y;
    // // 重载 < 操作符
    // bool operator<(const Node& other) const {
    //     if (x != other.x) return x < other.x;
    //     if (y != other.y) return y < other.y;
    //     return c < other.c;  // 最后比较c
    // }
    // 必须重载 == 用于 unordered_map 判断键相等
    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
};
struct NodeHash {
    size_t operator()(const Node& node) const {
        return (hash<int>()(node.x) * 131 + 
                hash<int>()(node.y));
    }
};
unordered_map<Node,int,NodeHash>dp; // dpxy0/1-当前为xy，轮到0/1（还未变化）需要多少轮
unordered_map<Node,bool,NodeHash>vis; 

int dfs(int x,int y)
{
    Node ini={x,y};
    if(dp[ini]) return dp[ini];
    dp[ini]=-1;

    if(x==0) return dp[ini]=1;
    if(y==0) return dp[ini]=2;

    int num=(x+y)%p;
    return dp[ini]=dfs(num,(num+y)%p);
}

void solve1()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y;
    cin>>x>>y;
    x%=p;
    y%=p;
    dfs(x,y);
    Node ini={x,y};
    int ans=dp[ini];
    if(ans==-1||ans==0) cout<<"error\n";
    else if(ans%2==1) cout<<"1\n";
    else cout<<"2\n";
    // if(ans==-1) return ans;
    // else return (ans%2);
}

int main()
{
    int T;
    cin>>T>>p;
    while(T--)
    {
        solve1();
    }
}