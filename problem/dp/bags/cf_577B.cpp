#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  if(n>m){
    cout<<"YES\n";
    return;
  }
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    a[i]%=m;
  }
  vector dp(m+1,vector<int>(m+1));
  bool f=false;
  for(int i=1;i<=n;++i){
    dp[i][a[i]]=1;
    for(int j=1;j<=m;++j){
        dp[i][j]|=dp[i-1][j];
        dp[i][(j+a[i])%m]|=dp[i-1][j];
    }
    f|=dp[i][0];
    if(f)break;
  }
  cout<<(f?"YES":"NO")<<'\n';
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