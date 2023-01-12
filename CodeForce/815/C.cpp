#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector mp(n,vector<int>(m));
  int sum=0;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
        char c;
        cin>>c;
        mp[i][j]=c-'0';
        if(mp[i][j])++sum;
    }
  }
  int beg=0x3f3f3f3f;
  for(int i=0;i<n-1;++i)
  {
    for(int j=0;j<m-1;++j)
    {
        int cnt=mp[i][j]+mp[i+1][j]+mp[i][j+1]+mp[i+1][j+1];
        if(cnt==0)continue;
        beg=min(beg,max(cnt-1,1));
    }
  }
  if(sum==0)
  {
    cout<<0<<'\n';
    return;
  }
  cout<<sum+1-beg<<'\n';
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