#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  int xmax=0,xmin=0,ymax=0,ymin=0;
  for(int i=0;i<n;++i)
  {
    int x,y;
    cin>>x>>y;
    xmax=max(x,xmax);
    xmin=min(x,xmin);
    ymax=max(y,ymax);
    ymin=min(y,ymin);
  }
  cout<<2*(xmax+ymax-ymin-xmin)<<'\n';
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