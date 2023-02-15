#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct edge
{
	int u,v,w,nxt;
};
vector<int>head;
int edge_cnt,node_cnt;
void add_edge(int u,int v,int w,vector<edge>& E)
{
	E.push_back({u,v,w,head[u]});
	head[u]=edge_cnt++;
}
vector<edge>E,E1;
vector<ll>value;
struct tarjan
{
	vector<ll>p;
    stack<int>S;
	int n;
    vector<int>dfn,low,scc;//邻接表的表头,dfs的访问顺序，栈中的最小dfs序,scc[i]属于哪个点
    vector<vector<int>>scc_vec;//每个缩完的点所包含的点
    int order;//order 表示dfn序
    tarjan(int n)
    {
        this->n=n;
		head.resize(n+1,-1);
        dfn.resize(n+1);
        low.resize(n+1);
        scc.resize(n+1);
		p.resize(n+1);
        scc_vec.resize(n+1);
        node_cnt=edge_cnt=order=0;
        while(S.size())S.pop();
    }

    void dfs(int now)
    {
        dfn[now]=low[now]=++order;
        S.push(now);
        for(int i=head[now];i!=-1;i=E[i].nxt)
        {
            int v=E[i].v;
            if(!dfn[v])
            {
                dfs(v);
                low[now]=min(low[now],low[v]);
            }
            else if(!scc[v])
            {
                low[now]=min(dfn[v],low[now]);
            }
        }
        if(dfn[now]==low[now])
        {
            ++node_cnt;
			while(1)
            {
                auto t=S.top();
                S.pop();
                scc_vec[node_cnt].push_back(t);
                scc[t]=node_cnt;
				value[node_cnt]+=p[t];
                if(t==now)break;
            }
        }
    }
	void tar()
	{
		value.resize(n+1);
		for(int i=1;i<=n;++i)
		{
			if(!dfn[i])
			{
				dfs(i);
			}
		}
	}
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}