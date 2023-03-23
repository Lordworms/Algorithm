#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node{
    int l,r,id;
};
void solve(){
  int n;
  cin>>n;
  vector<node>a(n);
  for(int i=0;i<n;++i){
    cin>>a[i].l>>a[i].r;
    a[i].id=i;
  }
  sort(a.begin(),a.end(),[&](node a,node b){
    return a.l==b.l?a.r>b.r:a.l<b.l;
  });
  for(int i=0;i<n-1;++i){
    if(a[i].r>=a[i+1].r){
        cout<<a[i+1].id+1<<' '<<a[i].id+1<<'\n';
        return;
    }
  }
  cout<<-1<<' '<<-1<<'\n';
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