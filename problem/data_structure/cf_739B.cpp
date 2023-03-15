#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int MOD=1e9+7;
using pii=pair<int,int>;
void solve(){
  int n;cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  vector<vector<int>>E(n),cost(E);
  for(int i=1;i<n;++i){
    int p,w;cin>>p>>w;
    --p;
    E[i].push_back(p);
    E[p].push_back(i);
    cost[i].push_back(w);
    cost[p].push_back(w);
  }
  vector<int>ans(n),dis(n);
  vector<pii>que;
  function<void(int,int)>dfs=[&](int x,int f){
    ans[x]=1;
    int pos=lower_bound(que.begin(),que.end(),make_pair(dis[x]-a[x],0ll))-que.begin()-1;//find the previous 
    if(pos>=0){
        ans[que[pos].second]--;
    }
    que.push_back({dis[x],x});
    for(int i=0;i<E[x].size();++i){
        int v=E[x][i],c=cost[x][i];
        if(v==f)continue;
        dis[v]=dis[x]+c;
        dfs(v,x);
        ans[x]+=ans[v];
    }
    que.pop_back();
  };
  dfs(0,-1);
  for(int i=0;i<n;++i){
    cout<<ans[i]-1<<' ';
  }
  return;
}
signed main(){
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