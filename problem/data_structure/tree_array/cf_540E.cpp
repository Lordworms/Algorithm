#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
#define lowbit(x) x&-x
void solve(){
  int n;cin>>n;
  vector<int>l(n+1),r(n+1),pre_pos,pre_value;
  map<int,int>mp;
  for(int i=1;i<=n;++i){
    cin>>l[i]>>r[i];
    mp[l[i]]=0;
    mp[r[i]]=0;
  }
  int cnt=0;
  pre_pos.push_back(0);
  pre_value.push_back(0);
  for(auto& k:mp){
    k.second=++cnt;
    pre_pos.push_back(cnt);
    pre_value.push_back(k.first);
  }
  vector<int>tree(cnt+1);
  for(int i=1;i<=n;++i){
    l[i]=mp[l[i]];
    r[i]=mp[r[i]];
  }
  auto add=[&](int x,int v){
    while(x<=cnt){
        tree[x]+=v;
        x+=lowbit(x);
    }
  };
  auto sum=[&](int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
  };
  for(int i=1;i<=n;++i){
    swap(pre_pos[l[i]],pre_pos[r[i]]);
  }
  ll ans=0;
  for(int i=1;i<=cnt;++i){
    add(pre_pos[i],1);
    ans+=i-sum(pre_pos[i]);
    ans+=(abs(pre_value[i]-pre_value[pre_pos[i]])-abs(i-pre_pos[i]));
  }
  cout<<ans<<'\n';
  return;
}
signed main(){
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