#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<int>a(m+2),b(a),c(a),d(a);
  cin>>c[1]>>d[1];
  a[1]=b[1]=0;
  for(int i=2;i<=m+1;++i){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  }
  vector dp(m+2,vector<int>(n+2));
  int ans=0;
  for(int i=1;i<=m+1;++i){
    for(int j=0;j<=n;++j){
        for(int k=0;k*b[i]<=a[i]&&k*c[i]<=n;++k){
            if(j>=k*c[i]){
                dp[i][j]=max(dp[i-1][j-c[i]*k]+d[i]*k,dp[i][j]);
            }
        }
        ans=max(ans,dp[i][j]);
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