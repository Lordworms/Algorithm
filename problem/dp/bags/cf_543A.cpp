#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int MOD;
void solve(){
  int n,m,b;
  cin>>n>>m>>b>>MOD;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  vector dp(m+1,vector<ll>(b+1));//dp[i][j], have written i lines of code and the remaining free bugs is j ways
  dp[0][0]=1;
  for(int id=1;id<=n;++id){
    for(int i=1;i<=m;++i){
        for(int v=a[id];v<=b;++v){
            dp[i][v]+=dp[i-1][v-a[id]];
            dp[i][v]%=MOD;
        }
    }
  }
  ll ans=0;
  for(int i=0;i<=b;++i){
    ans=(ans+dp[m][i])%MOD;
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