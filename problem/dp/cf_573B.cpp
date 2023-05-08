#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>h(n+2),l(n+2),r(n+2),dp(n+2);
  for(int i=1;i<=n;++i)cin>>h[i];
  for(int i=1;i<=n;++i)l[i]=min(l[i-1]+1,h[i]);
  for(int i=n;i>=1;--i)r[i]=min(r[i+1]+1,l[i]);
  int ans=0;
  for(int i=1;i<=n;++i){
    ans=max(ans,min(l[i],r[i]));
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