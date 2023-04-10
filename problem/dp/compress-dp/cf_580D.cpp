#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int>a(n);
  vector<vector<int>>mp(n+1,vector<int>(n+1));
  vector dp((1<<n),vector<ll>(n));
  for(int i=0;i<n;++i){
    cin>>a[i];
    dp[1<<i][i]=a[i];
  }
  for(int i=0;i<k;++i){
    int u,v,c;
    cin>>u>>v>>c;
    --u,--v;
    mp[u][v]=c;
  }
  for(int status=0;status<(1<<n);++status){
    for(int i=0;i<n;++i){
        if(status&(1<<i)){
            for(int j=0;j<n;++j){
                if(i!=j&&(status&(1<<j))){
                    dp[status][i]=max(dp[status][i],dp[status^(1<<i)][j]+a[i]+mp[j][i]);
                }
            }
        }
    }
  }
  ll ans=0;
  for(int status=0;status<(1<<n);++status){
    if(__builtin_popcount(status)!=m)continue;
    for(int i=0;i<n;++i){
        if(status&(1<<i)){
            ans=max(ans,dp[status][i]);
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