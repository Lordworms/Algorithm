#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define int ll
struct node{
    int v,id;
};
void solve(){
  int n;
  cin>>n;
  vector<node>a(n+1);
  vector<ll>sum(n+1);
  ll ori=0;
  for(int i=1;i<=n;++i){
    cin>>a[i].v;
    a[i].id=i;
    sum[i]=sum[i-1]+a[i].v;
    ori+=a[i].v*i;
  }
  auto slope=[&](int i,int j){
    return 1.0*(sum[i]-sum[j])/(i-j);
  };
  deque<int>q;
  q.push_back(0);
  for(int i=1;i<=n;++i){
    while(q.size()>=2&&slope((*(--(--q.end()))),i)<slope(*(--(--q.end())),*(--q.end()))){
        q.pop_back();
    }
    q.push_back(i);
  }
  ll ans=0;
  sort(a.begin()+1,a.end(),[&](node a,node b){
    return a.v<b.v;
  });
  for(int i=1;i<=n;++i){
    while(q.size()>=2&&slope(*q.begin(),*(++q.begin()))<a[i].v)q.pop_front();
    ans=max(ans,(q.front()-a[i].id)*a[i].v+sum[a[i].id]-sum[q.front()]);
  }
  cout<<ori+ans<<'\n';
  return;
}
signed main(){
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