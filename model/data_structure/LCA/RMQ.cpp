/*
    欧啦序列长度为2n-1（总点数n，总边数n-1s）
    欧拉序是在将一棵树转为一个序列，这个序列就叫欧拉序。
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//RMQ version LCA
struct LCA
{
    int n,s;
    const int MAXN=5e6+10;
    vector<int>dep,lg;
    vector<int>eular,pos;
    vector<vector<int>>E,st;
    vector<bool>vis;
    int cnt,edge_cnt;
    
    LCA(int num,int start):n(num),s(start)
    {
        edge_cnt=0;
        dep.resize(n<<1); 
        lg.resize(MAXN);
        eular.resize(n<<1);
        pos.resize(n<<1);//position in eular sequence
        E.resize(num+1);
        vis.resize(n+1,false);
        cnt=0;
        init_lg();
    }
    void init_lg()
    {
        lg[0]=lg[1]=0;
        for(int i=2;i<MAXN;++i)
        {
            lg[i]=lg[i/2]+1;
        }
    }
    void add_edge(int u,int v)
    {   
        ++edge_cnt;
        E[u].push_back(v);
        E[v].push_back(u);
        if(edge_cnt==n-1)
        {
           dfs(s,0);
           initST(2*n-1);
        }
    }
    void dfs(int now,int d)
    {
        eular[++cnt]=now;
        pos[now]=cnt;
        dep[cnt]=d;
        vis[now]=true;
        for(auto nxt:E[now])
        {
            if(vis[nxt])continue;
            dfs(nxt,d+1);
            eular[++cnt]=now;
            dep[cnt]=d;
        }
    }
    void initST(int n)
    {
        st.assign(n+1,vector<int>(31,0));
        for(int i=1;i<=n;++i)
        {
            st[i][0]=i;
        }
        for(int j=1;j<=lg[n];++j)
        {
            for(int i=0;i+(1<<(j-1))<=n;++i)
            {
                int a=st[i][j-1],b=st[i+(1<<j-1)][j-1];
                st[i][j]=dep[a]<dep[b]?a:b;
            }
        }
    }
    int commonFa(int x,int y)
    {
        x=pos[x],y=pos[y];//具体是哪一个无所谓，反正不会有dep小于他们的
        if(x>y)swap(x,y);
        int len=y-x+1;
        int a=st[x][lg[len]],b=st[y-(1<<lg[len])+1][lg[len]];
        int ans=dep[a]<dep[b]?a:b;
        return eular[ans];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int n,m,s;
  cin>>n>>m>>s;
  LCA lca(n,s);
  for(int i=0;i<n-1;++i)
  {
    int x,y;
    cin>>x>>y;
    lca.add_edge(x,y);
  }
  for(int i=0;i<m;++i)
  {
    int x,y;
    cin>>x>>y;
    cout<<lca.commonFa(x,y)<<'\n';
  }
  return 0;
}