#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e6;
void solve(){
  int n;
  cin>>n;
  vector tree(N<<2,vector<int>(2));
  vector<int>len(N<<2);
  int cnt=0;
  auto add=[&](int x){
    int u=0;
    for(int i=30;i>=0;--i){
        int bit=(x>>i)&1;
        if(!tree[u][bit]){
            tree[u][bit]=++cnt;
        }
        u=tree[u][bit];
        len[u]=i;
    }
  };
  for(int i=0;i<n;++i){
    int x;
    cin>>x;
    add(x);
  }
  function<ll(int)>dfs=[&](int u){
    ll sum=0;
    if(tree[u][0]&&tree[u][1])sum=(1<<len[tree[u][1]]);
    ll res=1e18;
    if(tree[u][0])res=min(res,dfs(tree[u][0]));
    if(tree[u][1])res=min(res,dfs(tree[u][1]));
    if(res==1e18)res=0;
    return sum+res;
  };
  cout<<dfs(0)<<'\n';
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