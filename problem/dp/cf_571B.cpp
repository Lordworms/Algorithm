#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e10;
int n,k;
int pos(int i,int j){
    return i*(n/k)+j;
}
void solve(){
  cin>>n>>k;
  int r=n%k;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a.begin()+1,a.end());
  vector dp(k+1,vector<ll>(k+1,INF));
  dp[0][0]=0;
  for(int i=1;i<=k;++i){
    for(int j=0;j<=min(r,i);++j){
       if(j){
            dp[i][j]=min(dp[i-1][j]+a[pos(i,j)]-a[pos(i-1,j)+1],dp[i-1][j-1]+a[pos(i,j)]-a[pos(i-1,j-1)+1]);
       }else{
            dp[i][j]=dp[i-1][j]+a[pos(i,j)]-a[pos(i-1,j)+1];
       }
    }
  }
  cout<<dp[k][r]<<'\n';
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