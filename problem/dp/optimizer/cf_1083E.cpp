/*
    dp[i]=max(j=[1,i-1]){dp[j]+Si-Sjandi-ai}
    k递减（移项可知）
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node{
    ll x,y,a;
};
void solve(){
  int n;
  cin>>n;
  vector<node>arr(n+1);
  vector<ll>dp(n+1);
  for(int i=1;i<=n;++i){
    cin>>arr[i].x>>arr[i].y>>arr[i].a;
  }
  sort(arr.begin()+1,arr.end(),[&](node a,node b){
    return a.x<b.x;
  });
  auto get_x=[&](int k){
    return arr[k].x;
  };
  auto get_y=[&](int k){
    return dp[k];
  };
  auto slope=[&](int u,int v){
    return (get_y(v)-get_y(u))/(get_x(v)-get_x(u));
  };
  deque<int>q;
  ll ans=0;
  for(int i=1;i<=n;++i){
    while(q.size()>=2&&slope(*(q.begin()),*(++q.begin()))>=arr[i].y)q.pop_front();
    dp[i]=arr[i].x*arr[i].y-arr[i].a;
    if(q.size())dp[i]=max(dp[i],dp[q.front()]+(arr[i].x-arr[q.front()].x)*arr[i].y-arr[i].a);
    ans=max(dp[i],ans);
    while(q.size()>=2&&slope(*(--q.end()),*(--(--q.end())))<=slope(*(--q.end()),i))q.pop_back();
    q.push_back(i);
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