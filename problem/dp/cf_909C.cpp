#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    char c;
    cin>>c;
    a[i]=(c=='f');
  }
  vector dp(n+3,vector<ll>(n+3));
  dp[0][0]=1;
  for(int i=1;i<=n;++i){
    if(a[i-1]){
        for(int j=1;j<n;++j){
            dp[i][j]=dp[i-1][j-1];
        }
    }else{
        for(int j=i-1;j>=0;--j){
            dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
        }
    }
  }
  ll ans=0;
  for(int i=0;i<n;++i){
    ans=(ans+dp[n][i])%MOD;
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