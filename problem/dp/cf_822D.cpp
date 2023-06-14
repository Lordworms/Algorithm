#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXM=5e6+10;
const ll INF=1e18;
void solve(){
  ll t,l,r;
  cin>>t>>l>>r;
  vector dp(MAXM,INF);
  dp[1]=0;
  for(int i=1;i<=r;++i){
    for(int j=2;j*i<=r;++j){
        dp[i*j]=min(dp[i*j],dp[i]+1ll*j*i*(j-1)/2);
    }
  }
  ll ans=0;
  ll base=1;
  for(int i=l;i<=r;++i){
    ans=(ans+base*(dp[i]%MOD))%MOD;
    base=base*t%MOD;
  }
  cout<<ans<<'\n';
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