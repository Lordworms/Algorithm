#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int m,w;
  cin>>w>>m;
  while(m){
    if(m%w==0){

    }else if(m%w==1){

    }else if(m%w==(w-1)){
        ++m;
    }
    else{
        cout<<"NO\n";
        return;
    }
    m/=w;
  }
  cout<<"YES\n";
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