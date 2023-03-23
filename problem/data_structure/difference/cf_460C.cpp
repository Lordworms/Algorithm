/*
    树上差分的细节，注意一哈
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct LCA
{
    int n,s;
    const int MAXN=5e6+10;
    vector<int>dep,lg;
    vector<int>eular,pos;
    vector<vector<int>>E,st;
    vector<vector<int>>id;
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
        id.resize(num+1);
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
    void add_edge(int u,int v,int i)
    {   
        ++edge_cnt;
        E[u].push_back(v);
        E[v].push_back(u);
        id[u].push_back(i);
        id[v].push_back(i);
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
                int a=st[i][j-1],b=st[i+(1<<(j-1))][j-1];
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
void solve(){
  int n;cin>>n;
  LCA lca(n,1);
  for(int i=1;i<=n-1;++i){
    int u,v;cin>>u>>v;
    lca.add_edge(u,v,i);
  }
  int k;cin>>k;
  vector<ll>add(n+1),sum(n+1);
  function<void(int,int)>dfs=[&](int x,int f){
    for(int i=0;i<lca.E[x].size();++i){
        int id=lca.id[x][i],v=lca.E[x][i];
        if(v==f)continue;
        dfs(v,x);
        add[x]+=add[v];
        sum[id]+=add[v];
    }
  };
  while(k--){
    int u,v;
    cin>>u>>v;
    add[u]++;
    add[v]++;
    int f=lca.commonFa(u,v);
    add[f]-=2;
  }
  dfs(1,0);
  for(int i=1;i<=n-1;++i){
    cout<<sum[i]<<" \n"[i==n-1];
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}