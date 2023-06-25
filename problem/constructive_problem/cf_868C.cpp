#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>vis(20);
  for(int i=1;i<=n;++i){
    int sta=0;
    for(int j=0;j<k;++j){
        int x;cin>>x;
        sta+=(1<<j)*x;
    }
    vis[sta]=1;
  }
  for(int i=0;i<16;++i){
    for(int j=0;j<16;++j){
        if(vis[i]&&vis[j]&&!(i&j)){
            cout<<"YES"<<'\n';
            return;
        }
    }
  }
  cout<<"NO"<<'\n';
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