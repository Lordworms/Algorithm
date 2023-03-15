#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
void solve(){
  int x=0,y=0;
  map<pii,int>mp;
  for(int i=0;i<4;++i){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x+=(y1==y2)&&(x1!=x2);
    y+=(x1==x2)&&(y1!=y2);
    mp[make_pair(x1,y1)]++;
    mp[make_pair(x2,y2)]++;
  }
  bool check=(x==2)&&(y==2);
  for(auto it:mp){
    if(it.second!=2){
      check=false;
    }
  }
  if(check){
    cout<<"YES\n";
  }else{
    cout<<"NO\n";
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