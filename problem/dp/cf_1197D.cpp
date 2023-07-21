#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<ll>dp(n+1),sum(n+1);
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    dp[i]=max(a[i]-k,0);
    sum[i]=sum[i-1]+a[i];
  } 
  ll ans=0;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      if(i-j>=0){
        dp[i]=max(dp[i],dp[i-j]-k+sum[i]-sum[i-j]);
        ans=max(ans,dp[i]);
      }
    }
  }
  cout<<ans<<'\n';
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in","r",stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}