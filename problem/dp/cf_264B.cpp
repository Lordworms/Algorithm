#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
vector<int>fac[MAXN];
void init(){
    for(int i=2;i<MAXN;++i){
        for(int j=i;j<MAXN;j+=i){
            fac[j].push_back(i);
        }
    }
}
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  map<int,int>dp;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    for(int f:fac[a[i]]){
        dp[f]=0;
    }
  }
  for(int i=1;i<=n;++i){
    int cur_max=-1;
    for(int f:fac[a[i]]){
        dp[f]+=1;
        cur_max=max(cur_max,dp[f]);
    }
    for(int f:fac[a[i]]){
        dp[f]=max(dp[f],cur_max);
    }
  }
  int ans=1;
  for(auto&k:dp){
    ans=max(k.second,ans);
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
  init();
  while(T--){
    solve();
  }
  return 0;
}