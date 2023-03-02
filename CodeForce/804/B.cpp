#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
vector<vector<int>>base={{1,0,0,1},{0,1,1,0},{0,1,1,0},{1,0,0,1}};
void solve()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
        cout<<base[i%4][j%4]<<" \n"[j==m-1];
    }
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