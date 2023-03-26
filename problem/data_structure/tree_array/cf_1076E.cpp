#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
#define lowbit(x) x&-x
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>E(n+1);
  for(int i=0;i<n-1;++i){
    int a,b;
    cin>>a>>b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  int max_dep=0;
  vector<int>dep(n+1);
  function<void(int,int)>dfs=[&](int x,int f){
    dep[x]=dep[f]+1;
    max_dep=max(dep[x],max_dep);
    for(int v:E[x]){
        if(v!=f){
            dfs(v,x);
        }
    }
  };
  dfs(1,1);
  vector<ll>tree(max_dep+2);
  auto add=[&](int x,int v){
    while(x<=max_dep){
        tree[x]+=v;
        x+=lowbit(x);
    }
  };
  auto sum=[&](int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
  };
  vector<ll>ans(n+1);
  vector<vector<pii>>query(n+1);
  function<void(int,int)>calc=[&](int x,int f){
    for(auto& k:query[x]){
        add(dep[x],k.second);
        add(k.first+1,-k.second);
    }
    ans[x]=sum(dep[x]);
    for(int v:E[x])if(v!=f)calc(v,x);
    for(auto& k:query[x]){
        add(dep[x],-k.second);
        add(k.first+1,k.second);
    }
  };
  int m;cin>>m;
  for(int i=1;i<=m;++i){
    int v,d,x;
    cin>>v>>d>>x;
    query[v].emplace_back(min(dep[v]+d,max_dep),x);
  }
  calc(1,1);
  for(int i=1;i<=n;++i){
    cout<<ans[i]<<" \n"[i==n];
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