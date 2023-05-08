#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1);
  vector<ll>sum(n+k+1),mx(n+k+1),pos(n+k+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
    if(i>=k)sum[i]-=a[i-k];
  }
  for(int i=n;i>=k;--i){
    if(sum[i]>=mx[i+1]){
        mx[i]=sum[i];
        pos[i]=i;
    }else{
        mx[i]=mx[i+1];
        pos[i]=pos[i+1];
    }
  }
  ll ans=0,pos1=0,pos2=0;
  for(int i=k;i<=n;++i){
    ll sm=sum[i]+mx[i+k];
    if(ans<sm){
        ans=sm;
        pos1=i-k+1;
        pos2=pos[i+k]-k+1;
    }
  }
  cout<<pos1<<' '<<pos2<<'\n';
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