#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  for(int i=1;i<=n;++i){
    int x;cin>>x;
    a[i]-=x;
  }
  sort(a.begin()+1,a.end());
  ll ans=0;
  for(int l=1,r=n;l<=n;++l){
    while(r>1&&a[l]+a[r]>0)--r;
    ans+=n-max(l,r);
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