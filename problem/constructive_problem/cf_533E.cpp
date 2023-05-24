#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  string s,t;
  cin>>s>>t;
  s=')'+s;
  t='('+t;
  int l=n+1,r=-1;
  for(int i=1;i<=n;++i){
    if(s[i]!=t[i]){
        l=min(l,i);
        r=max(r,i);
    }
  }
  int ans1=1,ans2=1;
  for(int i=l+1;i<=r;++i){
    if(s[i]!=t[i-1]){
        ans2=0;
    }
    if(t[i]!=s[i-1]){
        ans1=0;
    }
  }
  cout<<ans1+ans2<<'\n';
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