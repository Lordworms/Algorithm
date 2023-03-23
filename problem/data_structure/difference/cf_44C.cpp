#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<int>dif(n+2);
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    dif[a]++;
    dif[b+1]--;
  }
  for(int i=1;i<=n;++i){
    dif[i]+=dif[i-1];
  }
  for(int i=1;i<=n;++i){
    if(dif[i]!=1){
        cout<<i<<' '<<dif[i]<<'\n';
        return;
    }
  }
  cout<<"OK\n";
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