#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct rec{
    int a,b,c;
};
using pii=pair<ll,ll>;
void solve(){
  int n;cin>>n;
  vector<rec>recs(n);
  map<pii,pii>mp;
  ll ans=-1,left=-1,right=-1,flag=false;
  for(int i=0;i<n;++i){
    vector<ll>sq(3);
    for(int i=0;i<3;++i){
        cin>>sq[i];
    }
    sort(sq.begin(),sq.end());
    if(sq[0]>ans){
        flag=false;
        ans=sq[0];
        left=i;
    }
    auto pr=make_pair(sq[1],sq[2]);
    if(mp.find(pr)==mp.end()){
        mp[pr]=make_pair(i,sq[0]);
        continue;
    }
    ll new_max=std::min({sq[2],sq[1],mp[pr].second+sq[0]});
    if(new_max>ans){
        ans=new_max;
        left=mp[pr].first;
        right=i;
        flag=true;
    }
    if(sq[0]>mp[pr].second){
        mp[pr].second=sq[0];
        mp[pr].first=i;
    }
  }
  if(!flag){
    cout<<1<<'\n';
    cout<<left+1;
  }else{
    cout<<2<<'\n';
    cout<<left+1<<' '<<right+1<<'\n';
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