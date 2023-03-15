#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  string s;
  cin>>n>>s;
  int snt=0,cnt=0;
  for(int i=1;i<n;++i){
    if(s[i]==s[i-1]){
        ++snt;
    }
    else ++cnt;
  }
  cout<<cnt+min(2,snt)+1<<'\n'<<'\n';
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