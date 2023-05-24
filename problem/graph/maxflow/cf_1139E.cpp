#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<int>p(n+1),c(n+1);
  vector<vector<int>>E(5000+1);
  for(int i=1;i<=n;++i)cin>>p[i];
  for(int i=1;i<=n;++i)cin>>c[i];
  int d;cin>>d;
  vector<int>ans(d+1);
  int res=0;
  vector<int>invalid(n+1);
  vector<int>leave(d+1);
  for(int i=1;i<=d;++i){
    cin>>leave[i];
    invalid[leave[i]]=1;
  }
  for(int i=1;i<=n;++i){
    if(!invalid[i]){
        E[p[i]].push_back(c[i]);
    }
  }
  int cur_ans=0;
  vector<int>vis(n+1),match(m+1,-1);
  function<bool(int)>dfs=[&](int x){
    for(int v:E[x]){
        if(vis[v]==cur_ans){
            continue;
        }
        vis[v]=cur_ans;
        if(match[v]==-1||dfs(match[v])){
            match[v]=x;
            return true;
        }
    }
    return false;
  };
  for(int i=d;i>=1;--i){
    for(int j=res;;++j){
        ++cur_ans;
        if(!dfs(j)){
            res=j;
            break;
        }
    }
    ans[i]=res;
    E[p[leave[i]]].push_back(c[leave[i]]);
  }
  for(int i=1;i<=d;++i){
    cout<<ans[i]<<"\n";
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