#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=2e5+10;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  vector<ll>sum(MAXN),vis(sum);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    sum[a[i]]++;
  }
  sort(a.begin()+1,a.end());
  for(int i=a[n]-1;i>=0;--i){
    sum[i]+=sum[i+1];
  }
  ll ans=0;
  for(int i=1;i<=n;++i){
    if(vis[a[i]])continue;
    ll res=0;
    int cnt=1;
    for(int j=a[i];j<=a[n];j+=a[i]){
      res+=sum[j]*a[i];
      vis[j]=1;
    }
    ans=max(ans,res);
    vis[a[i]]=1;
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