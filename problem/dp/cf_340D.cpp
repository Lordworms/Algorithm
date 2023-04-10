#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  vector<int>opt;
  for(int i=0;i<n;++i){
    cin>>a[i];
    if(opt.size()==0||a[i]>=opt.back()){
        opt.push_back(a[i]);
    }else{
        int pos=lower_bound(opt.begin(),opt.end(),a[i])-opt.begin();
        opt[pos]=a[i];
    }
  }
  cout<<opt.size()<<'\n';
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