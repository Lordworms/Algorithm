#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=10020;
const int INF=0x3f3f3f3f;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<ll>num(n+1),fac5(n+1),fac2(n+1);
  for(int i=1;i<=n;++i){
    cin>>num[i];
    ll& x=num[i];
    while(x%5==0){
        fac5[i]++;
        x/=5;
    }
    while(x%2==0){
        fac2[i]++;
        x/=2;
    }
  }
  vector dp(n+1,vector<ll>(N,-INF));
  dp[0][0]=0;
  for(int i=1;i<=n;++i){
    for(int j=k;j>=1;--j){
        for(int l=N-1;l>=fac5[i];--l){
            if(num[i]){
                dp[j][l]=max(dp[j-1][l-fac5[i]]+fac2[i],dp[j][l]);
            }
        }
    }
  }
  ll ans=0;
  for(ll i=0;i<N;++i){
    ans=max(ans,min(i,dp[k][i]));
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