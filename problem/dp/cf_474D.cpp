#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
void solve(){
  int t,k;
  cin>>t>>k;
  vector<ll>dp(MAXN);
  vector<ll>sum(MAXN);
  dp[0]=1;
  for(int i=1;i<MAXN;++i){
    dp[i]=dp[i-1];
    if(i-k>=0){
        dp[i]=(dp[i]+dp[i-k])%MOD;
    }
    sum[i]=(sum[i-1]+dp[i])%MOD;
  }
  while(t--){
    int a,b;
    cin>>a>>b;
    cout<<(sum[b]-sum[a-1]+MOD)%MOD<<"\n";
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