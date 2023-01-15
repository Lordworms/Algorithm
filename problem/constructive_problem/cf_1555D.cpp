#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  string t="abc";
  vector sum(6,vector<int>(n+1));
  for(int i=0;i<6;++i)
  {
    for(int j=0;j<s.size();++j)
    {
        sum[i][j+1]=sum[i][j]+(t[j%3]!=s[j]);
    }
    next_permutation(t.begin(),t.end());
  }
  for(int i=0;i<m;++i)
  {
    int l,r;
    cin>>l>>r;
    int ans=n;
    for(int j=0;j<6;++j)
    {
        ans=min(ans,sum[j][r]-sum[j][l-1]);
    }
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