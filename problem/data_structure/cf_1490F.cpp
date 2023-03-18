#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  map<int,int,greater<int>>mp1,mp2;
  for(int i=0;i<n;++i){
    int x;cin>>x;
    mp1[x]++;
  }
  for(auto& k:mp1){
    mp2[k.second]++;
  }
  int ans=0x3f3f3f3f;
  for(auto &k1:mp2){
    int i=k1.first;
    int tmp=0;
    for(auto& k2:mp2){
        int j=k2.first;
        if(i==j)continue;
        tmp+=k1.first>k2.first?k2.second*k2.first:(k2.first-k1.first)*k2.second;
    }
    ans=min(ans,tmp);
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
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}