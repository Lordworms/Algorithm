#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,x;
  cin>>n;
  for(int i=0;i<n;++i)cin>>x;
  cout<<1<<' '<<n<<'\n';
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