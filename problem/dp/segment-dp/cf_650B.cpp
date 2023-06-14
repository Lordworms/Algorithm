#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,a,b,t;
  cin>>n>>a>>b>>t;
  string s;
  cin>>s;
  s='0'+s;
  vector<int>sum(n+1);
  for(int i=1;i<=n;++i){
    sum[i]=sum[i-1]+(s[i]=='w'?b+1:1);
  }
  auto calc=[&](int r){//r means left 
    for(int i=1;i<=r;++i){
        ll s1=sum[i]+sum[n]-sum[n-(r-i)];
        ll s2=min((i-1)*a*2+(r-i)*a,2*(r-i)*a+(i-1)*a);
        if(s1+s2<=t){
            return true;
        }
    }
    return false;
  };
  int l=0,r=n,ans=0;
  while(l<=r){
    int m=(l+r)>>1;
    if(calc(m)){
        ans=m;
        l=m+1;
    }else{
        r=m-1;
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