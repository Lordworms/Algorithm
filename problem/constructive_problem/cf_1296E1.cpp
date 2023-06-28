#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  string ans(s);
  vector<int>vis(n);
  char c='a';
  for(int i=0;i<s.size();++i){
    if(!vis[i]&&s[i]>=c){
        vis[i]=1;
        ans[i]='0';
        c=s[i];
    }
  }
  c='a';
  for(int i=0;i<s.size();++i){
    if(!vis[i]&&s[i]>=c){
        vis[i]=1;
        ans[i]='1';
        c=s[i];
    }
  }
  for(int i=0;i<n;++i){
    if(!vis[i]){
        cout<<"NO\n";
        return;
    }
  }
  cout<<"YES\n";
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