#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e7+10;
void solve(){
  vector<int>dp(MAXN),cnt(dp),vis(MAXN),prim(MAXN); 
  int maxn=0; 
  function<void(int)>init=[&](int lim){
    vis[1]=1;
    for(int i=2;i<=lim;++i){
        if(!vis[i]){
            dp[i]+=cnt[i];
            for(int j=2*i;j<=lim;j+=i){
                vis[j]=1;
                dp[i]+=cnt[j];
            }
        }
    }
  };
  int n;
  cin>>n;
  for(int i=0;i<n;++i){
    int x;
    cin>>x;
    cnt[x]++;
    maxn=max(x,maxn);
  }
  init(maxn);
  int q;
  cin>>q;
  for(int i=1;i<=maxn;++i){
    dp[i]+=dp[i-1];
  }
  while(q--){
    int l,r;
    cin>>l>>r;
    l=min(l-1,maxn);
    r=min(r,maxn);
    cout<<dp[r]-dp[l]<<'\n';
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