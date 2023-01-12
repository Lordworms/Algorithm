#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,sx,sy,d,m;
  cin>>n>>m>>sx>>sy>>d;
  int ans=n-1+m-1;
  if(min(sx-1,m-sy)<=d and min(n-sx,sy-1)<=d)
  {
    cout<<-1<<'\n';
  }
  else 
  {
    cout<<ans<<'\n';
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