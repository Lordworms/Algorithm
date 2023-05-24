#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node{
    int l,r;
};
void solve(){
  int n;
  cin>>n;
  vector<node>a(n);
  for(int i=0;i<n;++i){
    int x,w;
    cin>>x>>w;
    a[i].l=x-w;
    a[i].r=x+w;
  }
  sort(a.begin(),a.end(),[&](node a,node b){
    if(a.r==b.r){
        return a.l<b.l;
    }
    return a.r<b.r;
  });
  int ans=1,r=a[0].r;
  for(int i=1;i<n;++i){
    if(a[i].l>=r){
        ++ans;
        r=a[i].r;
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