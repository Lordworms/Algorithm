#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m,w;
  cin>>n>>m>>w;
  vector<int>a(n+1);
  int mina=0x3f3f3f3f;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    mina=min(mina,a[i]);
  }
  auto check=[&](int x){
    vector<int>dif(n+2);
    int res=0;
    ll v=0;
    for(int i=1;i<=n;++i){
        dif[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;++i){
        v+=dif[i];
        if(v<x){
            dif[i]+=(x-v);
            if(i+w<=n)dif[i+w]-=(x-v);
            res+=(x-v);
            if(res>m)break;
            v=x;
        }
    }
    return res<=m;
  };
  int l=mina,r=mina+m;
  while(l<=r){
    int mid=(l+r)>>1;
    if(check(mid)){
        l=mid+1;
    }else{
        r=mid-1;
    }
  }
  cout<<r<<'\n';
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