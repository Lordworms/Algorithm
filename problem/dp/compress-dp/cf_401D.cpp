#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=19;
ll dp[1<<N][101];
void solve(){
  vector<int>num;
  ll n,m;
  cin>>n>>m;
  memset(dp,-1,sizeof(dp));
  while(n){
    num.push_back(n%10);
    n/=10;
  }
  int len=num.size();
  sort(num.begin(),num.end());
  function<ll(int,int,int)>dfs=[&](int pos,int st,ll mod){
    if(!pos)return (ll)(mod==0);
    if(~dp[st][mod])return dp[st][mod];
    ll res=0;
    for(int i=0;i<len;++i){
        if(!((st&(1<<i)))&&(i==0||num[i]!=num[i-1]||(st&(1<<(i-1))))){
            res+=dfs(pos-1,st|(1<<i),(mod*10+num[i])%m);
        }
    }
    return dp[st][mod]=res;
  };
  ll ans=0;
  for(int i=0;i<len;++i){
    if(num[i]&&(i==0||num[i]!=num[i-1])){
        ans+=dfs(len-1,1<<i,num[i]%m);
    }
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