/*
    二维前缀和的题，分别处理横着和竖着分别能放多少个即可
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int h,w;
  cin>>h>>w;
  vector<vector<char>>mp(h+1,vector<char>(w+1));
  vector<vector<int>>hsum(h+1,vector<int>(w+1)),vsum(hsum);
  for(int i=1;i<=h;++i)for(int j=1;j<=w;++j)cin>>mp[i][j];
  for(int i=1;i<=h;++i)
  {
    for(int j=2;j<=w;++j)
    {
        int check=(mp[i][j]=='.'&&mp[i][j-1]=='.');
        hsum[i][j]=hsum[i-1][j]+hsum[i][j-1]-hsum[i-1][j-1]+check;
    }
  }
  for(int i=2;i<=h;++i)
  {
    for(int j=1;j<=w;++j)
    {
        int check=(mp[i][j]=='.'&&mp[i-1][j]=='.');
        vsum[i][j]=vsum[i-1][j]+vsum[i][j-1]-vsum[i-1][j-1]+check;
    }
  }
  int q;cin>>q;
  while(q--)
  {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans=hsum[x2][y2]-hsum[x2][y1]-hsum[x1-1][y2]+hsum[x1-1][y1];
    ans+=vsum[x2][y2]-vsum[x2][y1-1]-vsum[x1][y2]+vsum[x1][y1-1];
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}