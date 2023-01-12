#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
int Q[MAXN];
void solve()
{
  int head=1,tail=0;
  int n;
  cin>>n;
  vector<ll>a(n+1),b(n+1),dp(n+1);
  auto slope=[&](int i,int j)
  {
    return 1.0*(dp[j]-(double)dp[i])/(b[i]-b[j]);
  };
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)cin>>b[i];
  int h=1,t=0;
  for(int i=1;i<=n;++i)
  {
    while(h<t&&slope(Q[h],Q[h+1])<=a[i])++h;
    dp[i]=dp[Q[h]]+1ll*a[i]*b[Q[h]];
    while(h<t&&slope(Q[t-1],Q[t])>slope(Q[t],i))--t;
    Q[++t]=i;
  }
  cout<<dp[n]<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}