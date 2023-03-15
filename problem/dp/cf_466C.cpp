#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  vector<ll>sum(n+1);
  for(int i=1;i<=n;++i){
    cin>>sum[i];
    sum[i]+=sum[i-1];
  }
  if(sum[n]%3){
    cout<<0<<'\n';
    return;
  }
  ll ans=0,p1=0,opp=sum[n]/3;
  for(int i=1;i<n;++i){
    if(opp*2==sum[i]){
        ans+=p1;
    }
    if(opp==sum[i]){
        ++p1;
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