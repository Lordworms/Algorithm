#include <bits/stdc++.h>
using namespace std;
const int MAXN=30;
struct Edge{
    int u,v,next;
};
Edge E[MAXN];
vector<vector<int>>edges;
int head[MAXN];
int cnt;
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].next=head[u];
    head[u]=cnt++;
}
int dfn[MAXN],low[MAXN];
int times=0;
bool is_cut[MAXN];
vector<set<int>>bbc(MAXN);
stack<Edge>S;
int bbc_count=0;
void dfs(int now,int fa)
{
    dfn[now]=low[now]=++times;
    int child=0;
    for(int i=head[now];i!=-1;i=E[i].next)
    {
        int next=E[i].v;
        if(!dfn[next])//没有被访问过
        {
            S.push(E[i]);
            child++;
            dfs(next,now);
            low[now]=min(low[now],low[next]);
            if(low[next]>=dfn[now])//关键！！！！！！！！！！！！！！！！！
            {
                is_cut[now]=true;
                ++bbc_count;
                while(true)
                {
                  auto c=S.top();
                  bbc[bbc_count].insert(S.top().u);
                  bbc[bbc_count].insert(S.top().v);
                  S.pop();
                  if(c.u==now&&c.v==next)break;
                }
            }

        }
        else if(dfn[next]<dfn[now]&&next!=fa)//下一个点的连线为反边
        {
            S.push(E[i]);
            low[now]=min(low[now],dfn[next]);
        }
    }
    if(child==1&&fa==-1)
    {
        is_cut[now]=false;
    }
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(head,-1,sizeof(head));
   memset(dfn,0,sizeof(dfn));
   memset(low,0,sizeof(low));
   vector<vector<int>>edges={{1,2},{1,3},{2,3},{1,4},{1,5},{4,5},{1,6},{6,7},{7,8},{6,8}};
   for(auto& edge:edges)
   {
       add_edge(edge[0],edge[1]);
       add_edge(edge[1],edge[0]);
   }
   dfs(1,-1);
   int k=0;
   return 0;
}
