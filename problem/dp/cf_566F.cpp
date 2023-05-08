#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e6+10;
void solve(){
  int n;
  cin>>n;
  vector<int>dp(N);
  int ans=0;
  for(int i=1;i<=n;++i){
    int x;
    cin>>x;
    dp[x]++;
    for(int j=2*x;j<N;j+=x){
        dp[j]=max(dp[x],dp[j]);
    }
    ans=max(dp[x],ans);
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