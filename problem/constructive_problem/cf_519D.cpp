#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
map<ll,ll>mp[26];
void solve(){
  vector<int>p(26);
  for(int i=0;i<26;++i){
    cin>>p[i];
  }
  string s;
  cin>>s;
  ll cnt=0,ans=0;
  for(int i=0;i<s.size();++i){
    ans+=mp[s[i]-'a'][cnt];
    cnt+=p[s[i]-'a'];
    mp[s[i]-'a'][cnt]++;
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
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}