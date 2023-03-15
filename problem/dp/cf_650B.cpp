#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;cin>>n>>k;
  vector<vector<int>>pos(k+1,vector<int>(n+1)),a(pos);
  for(int i=1;i<=k;++i){
    for(int j=1;j<=n;++j){
      cin>>a[i][j];
      pos[i][a[i][j]]=j;
    }
  }
  vector<int>dp(n+1,1);
  int ans=0;
  for(int i=1;i<=n;++i){
    for(int j=1;j<i;++j){
      bool flag=true;
      for(int kk=2;kk<=k;++kk){
        if(pos[kk][a[1][i]]<=pos[kk][a[1][j]]){
          flag=false;
          break;
        }
      }
      if(flag){
        dp[i]=max(dp[i],dp[j]+1);
      }
    }
    ans=max(ans,dp[i]);
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