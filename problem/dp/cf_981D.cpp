#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
vector<ll>sum;
int n,k;
bool check(ll x){
    vector dp(n+1,vector<int>(n+1));// is it possible to get x when you put i books in the first j book shelves
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                for(int k=0;k<i;++k){
                    dp[i][j]|=(dp[k][j-1]&(((sum[i]-sum[k])&x)==x));
                }
            }
        }
        return dp[n][k];
}
void solve(){
  cin>>n>>k;
  sum.resize(n+1);
  for(int i=1;i<=n;++i){
    cin>>sum[i];
    sum[i]+=sum[i-1];
  }
  ll ans=0;
  for(int i=60;i>=0;--i){
    ll cur=ans|(1ll<<i);
    if(check(cur)){
        ans|=(1ll<<i);
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