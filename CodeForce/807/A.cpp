#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,x;
  cin>>n>>x;
  vector<int>a(2*n);
  for(int i=0;i<2*n;++i)
  {
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  for(int i=2*n-1;i>=n;--i)
  {
    if(a[i]<a[i-n]+x)
    {
        cout<<"NO\n";
        return;
    }
  }
  cout<<"YES\n";
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