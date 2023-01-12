#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int l=0,r=0;
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  sort(a.begin(),a.end());
  cout<<a[a.size()-1]+a[a.size()-2]-a[0]-a[1]<<'\n';
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