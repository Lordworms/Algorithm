#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  int cnt=0;
  for(int i=1;i<=k;++i)
  {
    if(a[i]<=k)
    {
        ++cnt;
    }
  }
  cout<<k-cnt<<'\n';
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