#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>pa(n+1);
  for(int i=2;i<=n;++i)
  {
    cin>>pa[i];
  }
  vector<int>l(n+1),r(l);
  vector<ll>a(n+1);
  for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
  int ans=0;
  for(int i=n;i>=1;--i)
  {
    if(a[i]<l[i])a[i]=r[i],++ans;
    if(a[i]>r[i])a[i]=r[i];
    a[pa[i]]+=a[i];
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}