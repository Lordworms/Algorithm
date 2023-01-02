#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;++i)
  {
    int x,y;
    cin>>x>>y;
  }
  cout<<(n<=m?"NO":"YES")<<'\n';
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