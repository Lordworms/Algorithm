#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
int dp[101][101][2];
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  for(int i=1;i<=n;++i){
    for(int j=0;j<=n;++j){
        dp[i][j][0]=dp[i][j][1]=INF;
    }
  }
  if(n>1&&a[1]%2==0){
    dp[1][n/2-1][0]=0;
  }
  if(a[1]==0||a[1]&1){
    dp[1][n/2][1]=0;
  }
  for(int i=2;i<=n;++i){
    for(int j=0;j<=n/2;++j){
        if(j>0&&!(a[i]&1)){
            dp[i][j-1][0]=std::min({dp[i][j-1][0],dp[i-1][j][1]+1,dp[i-1][j][0]});
        }if(i+j<=n&&(a[i]==0||(a[i]&1))){
            dp[i][j][1]=std::min({dp[i][j][1],dp[i-1][j][0]+1,dp[i-1][j][1]});
        }
    }
  }
  cout<<min(dp[n][0][0],dp[n][0][1])<<'\n';
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