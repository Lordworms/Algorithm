#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
void solve(){
  string s;
  cin>>s;
  int n=s.size();
  s='0'+s;
  vector<ll>ans;
  auto calc=[&](int lim){
    int l=1,r1=0,r2=1,res=0;
    int now_cnt=0;
    vector<int>cnt(26);
    for(;l<=n;++l){
        while(r1<n&&now_cnt<lim){
            if(++cnt[s[++r1]-'a']==1){
                ++now_cnt;
            }
        }
        if(now_cnt<lim)break;
        r2=max(r1,r2);
        while(r2<=n&&cnt[s[r2]-'a'])++r2;
        res+=(r2-r1);
        if(--cnt[s[l]-'a']==0)--now_cnt;
    }
    if(res>0)ans.push_back(res);
  };
  for(int i=1;i<=26;++i){
    calc(i);
  }
  cout<<ans.size()<<'\n';
  for(int i=0;i<ans.size();++i){
    cout<<ans[i]<<'\n';
  }
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