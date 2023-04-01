#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int c,d,n,m,k;
  cin>>c>>d>>n>>m>>k;
  int sum=n*m-k;
  if(sum<=0){
    cout<<0<<'\n';
    return;
  }
  int cnt=sum/n;
  int rem=sum%n;
  int ans=cnt*min(c,n*d)+min(rem*d,c);
  cout<<ans<<"\n";
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