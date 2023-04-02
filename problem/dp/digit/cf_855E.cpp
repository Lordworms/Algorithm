#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll dp[11][70][1024];
void solve(){
  int q;
  cin>>q;
  int base;
  memset(dp,-1,sizeof(dp));
  vector<int>num(70);
  function<ll(int,int,int,int)>dfs=[&](int pos,int sta,int lead,int flag){
    if(!pos)return (ll)!sta;
    if(!lead&&!flag&&dp[base][pos][sta]!=-1){
        return dp[base][pos][sta];
    }
    ll res=0;
    int lim=flag?num[pos]:base-1;
    for(int i=0;i<=lim;++i){
        res+=dfs(pos-1,(lead&&!i)?0:(sta^(1<<i)),lead&&(!i),flag&&(i==(lim)));
    }
    if(!lead&&!flag){
        dp[base][pos][sta]=res;
    }
    return res;
  };
  ll l,r;
  function<ll(ll)>get=[&](ll x){
    int pos=0;
    while(x){
        num[++pos]=x%base;
        x/=base;
    }
    return dfs(pos,0,1,1);
  };
  while(q--){
    cin>>base>>l>>r;
    ll right=get(r),left=get(l-1);
    cout<<get(r)-get(l-1)<<'\n';
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