#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  bool p=a[0]%2==0;
  ll ans=0;
  for(int i=1;i<n;++i)
  {
    if(p==(a[i]%2==0))
    {
        ++ans;
    }
    p=(a[i]%2==0);
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