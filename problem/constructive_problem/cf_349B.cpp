#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int v;cin>>v;
  vector<int>a(10);
  int minx=1e9;
  for(int i=0;i<9;++i){
    cin>>a[i];
    minx=min(a[i],minx);
  }
  int cnt=v/minx;
  if(!cnt){
    cout<<-1<<'\n';
    return;
  }
  while(cnt--){
    int pick=-1;
    for(int i=8;i>=0;--i){
        if((v-a[i])/minx==cnt&&v>=a[i]){
            cout<<(i+1);
            pick=i;
            break;
        }
    }
    v-=a[pick];
  }
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