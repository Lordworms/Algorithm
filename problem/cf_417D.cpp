#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const ll INF=1100000020000000000;
struct f{
    int x,k,sta;
};
void solve(){
  int n,m,b;
  cin>>n>>m>>b;//number of friend number of problems and number of cost for a single monitor
  vector<f>fri(n);
  for(int i=0;i<n;++i){
    int xi,ki,mi;//money the friend needs,monitor needs and number of problem the friend could solve
    cin>>xi>>ki>>mi;
    int sta=0;
    for(int j=0;j<mi;++j){
        int t;cin>>t;
        --t;
        sta|=(1<<t);
    }
    fri[i]={xi,ki,sta};
  }
  sort(fri.begin(),fri.end(),[&](f a,f b){
    return a.k<b.k;
  });
  vector<ll>dp(1<<m,INF);
  dp[0]=0;
  ll ans=INF;
  for(int i=0;i<n;++i){
    for(int j=0;j<(1<<m);++j){
        if(dp[j]<INF){
            dp[j|fri[i].sta]=min(dp[j|fri[i].sta],dp[j]+fri[i].x);
        }
    }
    ans=min(ans,dp[(1<<m)-1]+1ll*fri[i].k*b);
  }
  cout<<(ans>=INF?-1:ans)<<'\n';
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