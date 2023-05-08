#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1),l(n+1),r(n+1);
  map<int,int>mp;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    if(a[i]%k==0)l[i]=mp[a[i]/k];
    mp[a[i]]++;
  }
  mp.clear();
  int ans=0;
  for(int i=n;i>=1;--i){
    r[i]=mp[a[i]*k];
    ans+=(l[i]*r[i]);
    mp[a[i]]++;
  }
  cout<<ans<<'\n';
  return;
}
signed main(){
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