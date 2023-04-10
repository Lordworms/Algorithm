#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<string>mp(n+1);
  for(int i=1;i<=n;++i){
    cin>>mp[i];
    mp[i]='0'+mp[i];
  }
  vector<vector<int>>dp(m+1,vector<int>(n+1));
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
        if(mp[i][j]=='1'){
            dp[j][i]=dp[j-1][i]+1;
        }
    }
  }
  int ans=0;
  for(int j=1;j<=m;++j){
    sort(dp[j].begin()+1,dp[j].end(),greater<int>());
    for(int i=1;i<=n;++i){
        if(dp[j][i]==0)break;
        ans=max(dp[j][i]*i,ans);
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