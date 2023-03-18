#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  vector<int>s(n+1),cnt(n+2),b(n+2);
  for(int i=1;i<=n;++i){
    cin>>s[i];
    int l=i+2,r=min(n,i+s[i]);
    if(l<=r){
        cnt[l]++;cnt[r+1]--;
    }
  }
  for(int i=1;i<=n;++i){
    b[i]=b[i-1]+cnt[i];
  }
  for(int i=1;i<=n;++i){
    if(b[i]>=s[i]){
        b[i+1]+=(b[i]-s[i]+1);//since right now it only effect i+1
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i){
    ans+=max(0ll,s[i]-b[i]-1);
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
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}