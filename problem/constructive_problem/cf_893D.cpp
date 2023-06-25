#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,d;
  cin>>n>>d;
  vector<int>a(n+1);
  vector<ll>sum(n+1);
  vector<ll>suffix_sum(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
  }
  suffix_sum[n]=sum[n];
  for(int i=n-1;i>=1;--i){
    suffix_sum[i]=max(sum[i],suffix_sum[i+1]);
  }
  if(suffix_sum[1]>d){
    cout<<-1<<'\n';
    return;
  }
  ll cur=0,delta=0;
  int ans=0;
  for(int i=1;i<=n;++i){
    if(a[i]!=0){
        cur+=a[i];
    }else{//did some shit
        if(cur>=0)continue;
        ll cur_add=d-(delta+suffix_sum[i]);
        cur+=cur_add;
        delta+=cur_add;
        if(cur<0){
            cout<<-1<<'\n';
            return;
        }
        ++ans;
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