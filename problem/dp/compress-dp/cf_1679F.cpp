#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
void solve(){
  int n,m;
  cin>>n>>m;
  vector dp(n+1,vector<int>(1<<10));
  vector<int> a(1<<10),b(a);//a[i] means (i,*) b[i] means (*,i)
  for(int i=1;i<=m;++i){
    int u,v;
    cin>>u>>v;
    a[u]|=(1<<v);
    b[v]|=(1<<u);
  }
  dp[0][0]=1;
  for(int i=1;i<=n;++i){
    for(int sta=0;sta<(1<<10);++sta){
      for(int j=0;j<10;++j){
        if(sta&(1<<j))continue;//we could not pick some digit which could be placed earlier
        (dp[i][(sta&a[j])|b[j]]+=dp[i-1][sta])%=MOD;
      }
    }
  }
  int ans=0;
  for(int sta=0;sta<(1<<10);++sta){
    ans=(ans+dp[n][sta])%MOD;
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