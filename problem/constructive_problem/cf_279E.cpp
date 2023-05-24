#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s;
  cin>>s;
  s='0'+s;
  int ans=0;
  for(int i=s.size()-1;i;--i){
    if(s[i]=='1'){
      if(s[i-1]=='1')s[i]='0',s[i-1]='*';
      else ++ans;
    }
    else if(s[i]=='*'){
      if(s[i-1]=='1')s[i]='0',s[i-1]='*';
      else ++ans,s[i]='0',s[i-1]='1';
    }
  }
  if(s[0]=='1')++ans;
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