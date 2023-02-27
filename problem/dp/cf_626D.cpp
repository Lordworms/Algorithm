#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using db=double;
const int MAXN=5010;
void solve()
{
  db n;
  cin>>n;
  db xi=1/(n*(n-1)/2);
  vector<db>dp(MAXN),f(2*MAXN),pre(2*MAXN);
  vector<db>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a.begin()+1,a.end());
  for(int i=1;i<=n;++i)
  {
    for(int j=i+1;j<=n;++j)
    {
        dp[a[j]-a[i]]+=xi;
    }
  }
  for(int i=1;i<=5000;++i)
  {
    for(int j=1;j<=5000;++j)
    {
        f[i+j]+=dp[i]*dp[j];
    }
  }
  for(int i=1;i<=10000;++i)
  {
    pre[i]=pre[i-1]+f[i];
  }
  db ans=0;
  for(int i=1;i<=5000;++i)
  {
    ans+=dp[i]*pre[i-1];
  }
  cout<<ans<<'\n';
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