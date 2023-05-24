#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s;
  cin>>s;
  int n=s.size();
  int cnt_1=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='1')++cnt_1;
  }
  int ans=INT_MAX;
  int cnt_0=0;
  for(int l=0,r=-1;l<n;++l){
    while(r<n&&cnt_0<cnt_1){
        ++r;
        if(s[r]=='1'){
            cnt_1--;
        }else{
            cnt_0++;
        }
        ans=min(ans,max(cnt_0,cnt_1));
    }
    if(s[l]=='0'){
        --cnt_0;
    }else{
        ++cnt_1;
    }
    ans=min(ans,max(cnt_0,cnt_1));
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