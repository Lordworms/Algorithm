#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e6+5;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>vis(n+1),a(vis),num(vis),lens(vis),v(vis);//num: number of rings that has length i,lens: length of i ring
  int cnt=0;//count of total rings;(distinct size)
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i){
    int now=i,len=0;
    while(!vis[now]){
        vis[now]=1;
        ++len;
        now=a[now];
    }
    if(num[len])num[len]++;
    else num[len]=1,lens[++cnt]=len;
  }
  ll ans=0;
  for(int i=1;i<=cnt;++i){
    ans+=lens[i]/2*num[lens[i]];
  }
  if(ans>=k){
    ans=k*2;
  }else{
    ans+=k;
  }
  ans=min(ans,(ll)n);
  int tot=0;
  for(int i=1;i<=cnt;++i){
    for(int j=1;j<=num[lens[i]];j<<=1){
        v[++tot]=j*lens[i];
        num[lens[i]]-=j;
    }
    if(num[lens[i]]){
        v[++tot]=num[lens[i]]*lens[i];
    }
  }
  bitset<N>dp;
  dp.set(0);
  for(int i=1;i<=tot;++i){
    dp|=(dp<<v[i]);
  }
  if(dp.test(k)){
    cout<<k<<' '<<ans<<'\n';
  }else{
    cout<<k+1<<' '<<ans<<'\n';
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