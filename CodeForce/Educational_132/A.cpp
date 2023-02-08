#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int x;cin>>x;
  vector<int>a(4);
  for(int i=1;i<=3;++i)cin>>a[i];
  if(a[x]==0||a[a[x]]==0)
  {
    cout<<"NO\n";
    return;
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