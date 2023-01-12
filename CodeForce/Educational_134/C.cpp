/*
    find the first element that could satisfy that 
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n),b(n);
  vector<int>d(n);
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<n;++i)cin>>b[i];
  vector ans(2,vector<int>(n));
  ans[1][n-1]=b.back()-a.back();
  ans[0][0]=b.front()-a.front();
  for(int i=0;i<n;++i)
  {
    ans[0][i]=b[lower_bound(b.begin(),b.end(),a[i])-b.begin()]-a[i];
  }
  multiset<int>s(b.begin(),b.end());
  for(int i=n-1;i>=0;--i)
  {
    ans[1][i]=*(--s.end())-a[i];
    s.erase(s.lower_bound(a[i]));
  }
  for(int i=0;i<2;++i)
  {
    for(int j=0;j<n;++j)
    {
        cout<<ans[i][j]<<' ';
    }
    cout<<'\n';
  }
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