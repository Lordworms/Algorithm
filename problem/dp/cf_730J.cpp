#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct bt{
    int rem,vol;
};
void solve(){
  int n;cin>>n;
  vector<bt>a(n+1);
  ll total=0;
  for(int i=1;i<=n;++i){
    cin>>a[i].rem;
    total+=a[i].rem;
  }
  for(int i=1;i<=n;++i){
    cin>>a[i].vol;
  }
  sort(a.begin()+1,a.end(),[&](bt a,bt b){
    return a.vol>b.vol;
  });
  int ans1=0;
  ll sum=0;
  while(total>sum)sum+=a[++ans1].vol;
  vector dp(n+1,vector<ll>(sum+1,-1000000));
  dp[0][0]=0;
  for(int i=1;i<=n;++i){
    for(int j=ans1;j>=1;--j){
        for(ll k=sum;k>=a[i].vol;--k){
            dp[j][k]=max(dp[j][k],dp[j-1][k-a[i].vol]+a[i].rem);
        }
    }
  }
  ll ans2=0;
  for(int i=total;i<=sum;++i){
    ans2=max(ans2,dp[ans1][i]);
  }
  cout<<ans1<<' '<<total-ans2<<'\n';
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