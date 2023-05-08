#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1e18;
void solve(){
  ll n,p;
  cin>>n;
  vector<int>a(n+1);
  vector<double>fac(n+1);
  fac[0]=fac[1]=1;
  ll sum=0;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    fac[i]=fac[i-1]*i;
    sum+=a[i];
  }
  cin>>p;
  if(sum<=p){
    cout<<n<<'\n';
    return;
  }
  vector dp(n+1,vector<ll>(p+1,0));
  dp[0][0]=1;
  for(int i=1;i<=n;++i){
    for(int j=i;j>=1;--j){
        for(int v=p;v>=a[i];--v){
            dp[j][v]+=dp[j-1][v-a[i]];
        }
    }
  }
  double ans=0;
  for(int i=1;i<=n;++i){
    for(int j=0;j<=p;++j){
        ans+=(double)dp[i][j]*fac[i]*fac[n-i];
    }
  }
  cout<<ans/fac[n]<<'\n';
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