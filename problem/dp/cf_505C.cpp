#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=30001;
const int LIM=250;
void solve(){
  int n,d;
  cin>>n>>d;
  vector<int>a(N);
  for(int i=0;i<n;++i){
    int x;
    cin>>x;
    a[x]++;
  }
  vector dp(N,vector<ll>(2*LIM+2,-1e8));
  dp[d][LIM]=a[d];
  ll ans=-1;
  for(int i=1;i<N;++i){
    for(int j=0;j<=2*LIM;++j){
        int last_pos=i-(j+d)+250;
        if(last_pos<0||last_pos>=i)continue;
        for(int k=-1;k<=1;++k){
            if(j+k>0){
                dp[i][j]=max(dp[last_pos][j+k]+a[i],dp[i][j]);
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