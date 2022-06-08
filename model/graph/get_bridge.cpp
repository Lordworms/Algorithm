#include <bits/stdc++.h>
using namespace std;
const int MAXN=50;
struct Edge{
    int u,v,next;
};
Edge E[MAXN];
vector<vector<int>>edges={{1,2},{2,3},{1,3},{1,4},{1,5},{4,5},{1,6},{6,7},{7,8},{6,8}};
int head[MAXN];
int dfn[MAXN],low[MAXN];
int cnt,times;
stack<int>S;
int bbc_count=0;
vector<vector<int>>bbc(MAXN);
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].next=head[u];
    head[u]=cnt++;
}   
void dfs(int now,int fa)
{
    dfn[now]=low[now]=++times;
    S.push(now);
    for(int i=head[now];i!=-1;i=E[i].next)
    {
        int next=E[i].v;
        if(!dfn[next])//未被访问过
        {
            dfs(next,now);
            low[now]=min(low[next],low[now]);
        }
        else if(dfn[next]<dfn[now]&&fa!=next)
        {
            low[now]=min(dfn[next],low[now]);
        }
    }
    if(low[now]==dfn[now])
    {
        while(true)
        {
            int x=S.top();
            S.pop();
            bbc[bbc_count].push_back(x);
            if(x==now)break;
        }
        ++bbc_count;
    }
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(head,-1,sizeof(head));
   for(auto&edge:edges)
   {
       add_edge(edge[0],edge[1]);
       add_edge(edge[1],edge[0]);
   }
   dfs(1,-1);
   return 0;
}
