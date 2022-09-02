/*
    LCA没有太多值得一提的性质，只有一个性质用的比较多
    d(u,v)=h(u)+h(v)-2*h(LCA(u,v))
    h表示到根结点的距离
    这里只写一个倍增的方法

*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10;
vector<int>E[MAXN];
vector<int>W[MAXN];
int fa[MAXN][31],cost[MAXN][31];//cost[i][j]表示编号为i的点向上跳2^j次方所需要的cost
int dep[MAXN];
int n;
void dfs(int now,int f)
{
    fa[now][0]=f;
    dep[now]=dep[f]+1;
    for(int i=1;i<31;++i)
    {
        fa[now][i]=fa[fa[now][i-1]][i-1];//显而易见
        //cost[now][i]=cost[fa[now][i-1]][i-1]+cost[now][i-1];
    }
    for(int i=0;i<E[now].size();++i)
    {
       if(E[now][i]==f)continue;//不是now
       //cost[E[now][i]][0]=W[now][i];
       dfs(E[now][i],now);
    }
}
//倍增求LCA,这里只展示了求公共祖先的部分，没有展示别的，但是你可以运用之前的那条定理求出任意两点的最短距离
int LCA(int x,int y)
{
    //y要比x深，不然复杂度增大
    if(dep[x]>dep[y])swap(x,y);
    int dis=dep[y]-dep[x];
    int ans=0;
    for(int j=0;dis;dis>>=1,++j)if(dis&1)y=fa[y][j];
    if(y==x)return y;
    //开始倍增
    for(int j=30;j>=0&&y!=x;--j)
    {
        if(fa[x][j]!=fa[y][j])
        {
            x=fa[x][j],y=fa[y][j];
        }
        else return fa[x][j];
    }
    return 1;
}
void init()
{
    memset(fa,0,sizeof(fa));
    memset(cost,0,sizeof(cost));
    memset(dep,0,sizeof(dep));
}