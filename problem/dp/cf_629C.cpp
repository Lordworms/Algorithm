#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  s=')'+s;
  vector dp(2001,vector<ll>(2001));
  dp[0][0]=1;
  for(int i=1;i<=2000;++i){
    dp[i][0]=dp[i-1][1];
    for(int j=1;j<=i;++j){
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
    }
  }
  int min_bs=0,bs=0;
  for(int i=1;i<=m;++i){
    if(s[i]=='(')++bs;
    else --bs;
    min_bs=min(bs,min_bs);
  }
  ll ans=0;
  for(int i=0;i<=n-m;++i){
    for(int j=0;j<=i;++j){
        if(j+min_bs>=0 && j+bs<=n-m-i){
            ans=(ans+(dp[i][j]*dp[n-m-i][j+bs])%MOD)%MOD;
        }
    }
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