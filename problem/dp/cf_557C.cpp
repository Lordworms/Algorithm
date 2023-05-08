#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=1e9+1;
void solve(){
  int n;
  cin>>n;
  vector<ll>l(n+2),d(n+2);
  for(int i=1;i<=n;++i)cin>>l[i];
  for(int i=1;i<=n;++i)cin>>d[i];
  vector<pair<ll,ll>>a(n+2),b(n+2);
  for(int i=1;i<=n;++i){
    a[i]=make_pair(d[i],l[i]);
    b[i]=make_pair(l[i],d[i]);
  }
  a[0]=b[0]=make_pair(0,0);
  a[n+1]=b[n+1]=make_pair(INT_MAX,INT_MAX);
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int len=0;
  ll p=0,rem=0;
  for(int i=1;i<=n;++i){
    ++len;
    p+=b[i].second;//p represent the total remaining of the same height
    if(b[i].first!=b[i+1].first){
        int sub=n;
        while(sub&&len>1){//keep no more than len's other shit
            if(a[sub].second<b[i].first){
                p+=a[sub].first;
                --len;
            }
            --sub;
        }
        rem=max(rem,p);
        p=len=0;
    }
  }
  ll sum=accumulate(d.begin(),d.end(),0ll);
  cout<<sum-rem<<'\n';
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