/*
    树链剖分用于将树分割成若干条链的形式，以维护树上路径的信息。

具体来说，将整棵树剖分为若干条链，使它组合成线性结构，然后用其他的数据结构维护信息。

树链剖分（树剖/链剖）有多种形式，如 重链剖分，长链剖分 和用于 Link/cut Tree 的剖分（有时被称作“实链剖分”），大多数情况下（没有特别说明时），“树链剖分”都指“重链剖分”。

重链剖分可以将树上的任意一条路径划分成不超过O(logn)条连续的链，每条链上的点深度互不相同（即是自底向上的一条链，链上所有点的 LCA 为链的一个端点）。

重链剖分还能保证划分出的每条链上的节点 DFS 序连续，因此可以方便地用一些维护序列的数据结构（如线段树）来维护树上路径的信息。

如：
    1.修改 树上两点之间的路径上 所有点的值。
    2.查询 树上两点之间的路径上 节点权值的 和/极值/其它（在序列上可以用数据结构维护，便于合并的信息）。
    3.除了配合数据结构来维护树上路径信息，树剖还可以用来 O(logn)（且常数较小）地求 LCA。在某些题目中，还可以利用其性质来灵活地运用树剖

简介：
    有以下定义
    1.每个节点的值最大的子节点为其重子节点
    2.轻子节点为剩余的所有节点
    3.指向重子节点的边为重边
    4.指向轻子节点的边为轻边
    若干条首尾衔接的重边构成 重链。把落单的结点也当作重链，那么整棵树就被剖分成若干条重链。
好了，说了这么多，那咋求呢？
两遍dfs求解
第一遍：
    1.第一个 DFS 记录每个结点的父节点（father）、深度（deep）、子树大小（size）、重子节点（hson）。
    2.第二个 DFS 记录所在链的链顶（top，应初始化为结点本身）、重边优先遍历时的 DFS 序（dfn）、DFS 序对应的节点编号（rank）。

*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
//分别代表父亲节点、重儿子节点，子节点数量、i所在的重链的顶部节点、i的dfs序、dfs序对应的编号(rank[dfn[x]]=x),节点深度
int fa[MAXN],hson[MAXN],siz[MAXN],top[MAXN],dfn[MAXN],rnk[MAXN],dep[MAXN];
int h[MAXN];
int cnt;
struct edge{
    int u,v,w,nxt;
}E[MAXN];
void dfs1(int now)
{
    hson[now]=-1;
    siz[now]=1;
    for(int j=h[now];j;j=E[j].nxt)
    {
       int v=E[j].v;
       if(!dep[v])
       {
            dep[v]=dep[now]+1;
            fa[v]=now;
            dfs1(v);
            siz[now]+=siz[v];
            if(hson[now]==-1||siz[v]>siz[hson[now]])hson[now]=v;
       } 
    }
}
void dfs2(int now,int t)
{
    top[now]=t;
    dfn[now]=++cnt;
    rnk[cnt]=now;
    if(hson[now]==-1)return;//没有重子节点
    dfs2(hson[now],t);// 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
    for(int j=h[now];j;j=E[j].nxt)
    {
        int v=E[j].v;
        if(v==hson[now]||v==fa[now])continue;
        dfs2(v,v);
    }   

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}