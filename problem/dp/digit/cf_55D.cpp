#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=2520;
ll dp[50][N+1][50];
ll gcd(ll a,ll b){
    return b?a:gcd(b,a%b);
}
void solve(){
  int t;cin>>t;
  memset(dp,-1,sizeof(dp));
  vector<int>mp(N+1);
  int cnt=0;
  for(int i=1;i<=N;++i){
    if(2520%i==0){
        mp[i]=++cnt;
    }
  }
  vector<int>num(50);
  function<ll(int,int,int,int)>dfs=[&](int pos,int pre,int mod,int flag){
    if(!pos)return (ll)(pre%mod==0);
    if(!flag&&dp[pos][pre][mp[mod]]!=-1){
        return dp[pos][pre][mp[mod]];
    }
    ll res=0;
    int lim=flag?num[pos]:9;
    for(int i=0;i<=lim;++i){
        res+=dfs(pos-1,(pre*10+i)%N,i==0?mod:mod*i/gcd(mod,i),flag&&(i==lim));
    }
    if(!flag){
        dp[pos][pre][mp[mod]]=res;
    }
    return res;
  };
  function<ll(ll)>get=[&](ll x){
    int pos=0;
    while(x){
        num[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,1,1);
  };    
  while(t--){
    ll l,r;
    cin>>l>>r;
    cout<<get(r)-get(l-1)<<'\n';
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