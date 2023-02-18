/*
    树的重心的定义：以该点为根，其子树的大小最小，那么该点就是这棵树的重心
    性质：
        ①一棵树最少有一个重心，最多有两个重心，若有两个重心，则他们相邻（即连有直接边）。

        ②树上所有点到某个点的距离和里，到重心的距离和最小；若有两个重心，则其距离和相同。

        ③若以重心为根，则所有子树的大小都不超过整棵树的一半。否则可以通过平移使得最大子树的大小缩小至整树的一半，剩下子树的大小最大为 n/2 -1。此时新平移到的点才是真正的重心。
        
        ④在一棵树上添加或删除一个叶子节点，其重心最多平移一条边的距离。
        
        ⑤两棵树通过连一条边组合成新树，则新树重心在原来两棵树的重心的连线上。

*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
int siz[N],wgt[N];//size and weight, weight mean max sontree
int n,mi=INF,ans;//mi=min max size, ans=重心
vector<vector<int>>E;
void dfs(int now,int fa)
{
    siz[now]=1;
    wgt[now]=0;
    for(int i=0;i<E[now].size();i++)
    {
        int to=E[now][i];
        if(to==fa) continue;
        dfs(to,now);
        siz[now]+=siz[to];
        wgt[now]=max(wgt[now],siz[to]);
    }
    wgt[now]=max(wgt[now],n-siz[now]);
    if(wgt[now]<mi) mi=wgt[now],ans=now;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}