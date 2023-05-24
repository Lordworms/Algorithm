#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
double eps=1e-7;
void solve(){
  int n;
  cin>>n;
  double sum=0;
  int cnt=0;
  vector<double>a(2*n+1);
  for(int i=1;i<=2*n;++i){
    cin>>a[i];
    sum+=a[i]-floor(a[i]);
    if(a[i]-floor(a[i])<eps){
        ++cnt;
    }
  }
  double ans=6e10;
  for(int i=n;i>=n-cnt;--i){
    ans=min(ans,fabs(i-sum));
  }
  cout << setiosflags(ios::fixed) << setprecision(3) << ans << endl;
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