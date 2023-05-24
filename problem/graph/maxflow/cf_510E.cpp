#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
struct Dinic
{
  struct Edge
  {
    int from,to;
    ll cap;
    Edge(int f,int t,int c):from(f),to(t),cap(c){}
  };
  int n,m,s,t;//size of point and line and the start point and end point
  vector<int>d,cur;
  vector<bool>vis;
  vector<Edge>E;
  vector<vector<int>>G;
  const int INF=0x3f3f3f3f;
  Dinic(int n,int m):n(n),m(m)
  {
    d.resize(n+1);
    vis.resize(n+1,false);
    G.resize(n+1);
    cur.resize(n+1);
  }
  void add_edge(int from,int to,int cap)
  {
    E.push_back({from,to,cap});
    G[from].push_back(E.size()-1);
    E.push_back({to,from,0});
    G[to].push_back(E.size()-1); 
  }
  bool bfs()//get the depth of every point
  {
    fill(vis.begin(),vis.end(),false);
    queue<int>q;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
      int x=q.front();
      q.pop();
      for(int i=0;i<G[x].size();++i)
      {
        auto& e=E[G[x][i]];
        if(!vis[e.to]&&e.cap)
        {
          vis[e.to]=1;
          d[e.to]=d[x]+1;
          q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  ll dfs(int x,ll a)
  {
    if(x==t||a==0)return a;
    ll res=0,f;
    for(int& i=cur[x];i<G[x].size();++i)
    {
      auto& e=E[G[x][i]];
      if(d[x]+1==d[e.to]&&e.cap)
      {
        int f=dfs(e.to,min(a-res,e.cap));
        e.cap-=f;
        E[G[x][i]^1].cap+=f;
        res+=f;
        if(res==a)break;
      }
    }
    return res;
  }
  ll maxflow(int s,int t)
  {
    this->s=s;
    this->t=t;
    ll ans=0;
    while(bfs())
    {
      fill(cur.begin(),cur.end(),0);
      ans+=dfs(s,INF);//INF is the now flow
    }
    return ans;
  }
};
void solve(){
  int n;
  cin>>n;
  vector<int>f(n+1);
  for(int i=1;i<=n;++i)cin>>f[i];
  auto check_prime=[&](int num){
    for(int i=2;i<=sqrt(num);++i){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
  };
  Dinic dinic(n+3,0);
  int S=0,T=n+1;
  auto check=[&](){
    vector<int>odd,even;
    for(int i=1;i<=n;++i){
        if(f[i]&1){
            odd.push_back(i);
            dinic.add_edge(S,i,2);
        }else{
            even.push_back(i);
            dinic.add_edge(i,T,2);
        }
    }
    for(int i=0;i<odd.size();++i){
        for(int j=0;j<even.size();++j){
            if(check_prime(f[odd[i]]+f[even[j]])){
                dinic.add_edge(odd[i],even[j],1);//odd->even
            }
        }
    }
    auto maxflow=dinic.maxflow(S,T);
    return maxflow==n;
  };
   //first checkout whether it is possible to arrange all foxes
  if(!check()){
    cout<<"Impossible\n";
    return;
  }
  vector<vector<int>>groups;
  //then we use dfs to arrange all foxes
  vector<int>vis(n+1);
  function<void(int)>dfs=[&](int cur){
    groups.back().push_back(cur);
    vis[cur]=1;
    for(int id:dinic.G[cur]){
        auto e=dinic.E[id];
        if(e.to==S||e.to==T||vis[e.to])continue;
        if((e.cap==0&&f[e.from]%2==1)||(dinic.E[id^1].cap==0&&f[e.to]%2==1)){
            dfs(e.to);
        }
    }
  };
  for(int i=1;i<=n;++i){
    if(!vis[i]){
        groups.push_back(vector<int>());
        dfs(i);
    }
  }
  cout<<groups.size()<<'\n';
  for(int i=0;i<groups.size();++i){
    cout<<groups[i].size()<<' ';
    for(int num:groups[i]){
        cout<<num<<' ';
    }
    cout<<'\n';
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