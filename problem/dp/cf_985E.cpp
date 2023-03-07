#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=5e5+10;
void solve()
{
  int n,k,d;
  cin>>n>>k>>d;
  vector<ll>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a.begin()+1,a.end());
  vector<ll>dp(n+1);dp[0]=1;
  int r=1;
  for(int i=0;i<=n;++i)
  {
    if(dp[i]==0)continue;
    r=max(i+k,r);
    while(r<=n&&a[r]-a[i+1]<=d)
    {
        dp[r]=1;
        ++r;
    }
  }
  cout<<(dp[n]?"YES":"NO")<<'\n';
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