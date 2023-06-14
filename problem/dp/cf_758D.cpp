#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define EPS 0.00000001
const ll INF=1000000000000000000;
void solve(){
  ll n;
  cin>>n;
  string s;
  cin>>s;
  int m=s.size();
  vector dp(m+1,vector<ll>(m+1));
  for(int i=1;i<=m;++i){
    for(int j=1;j<=i;++j){
      dp[i][j]=INF;
    }
  }
  s='0'+s;
  for(ll i=1;i<=m;++i){
    for(ll j=1;j<=i;++j){
      ll cur_val=0,base=1;
      for(ll k=1;i-k>=j-1;++k){
        cur_val+=((ll)(s[i-k+1]-'0'))*base;
        if(cur_val>=n||base>=n){
          break;
        }
        base*=10;
        if(j==1&&k!=i){
          continue;
        }
        if(!(s[i-k+1]-'0'==0&&k!=1)){
          if(log(dp[i-k][j-1])+log(n)-log(INF-cur_val)<=EPS){
            dp[i][j]=min(dp[i][j],dp[i-k][j-1]*n+cur_val);
          }
        }
      }
    }
  }
  cout<<*min_element(dp[m].begin()+1,dp[m].begin()+m+1)<<'\n';
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