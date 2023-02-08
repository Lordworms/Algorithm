#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  if(n<=k)
  {
    for(char c='a';c<='a'+n-1;++c)
    {
        cout<<c;
    }
    cout<<'\n';
    return;
  }
  string ans;
  for(int i=0;i<k;++i)
  {
    ans+=('a'+i);
    for(int j=i+1;j<k;++j)
    {
        ans+=('a'+i);
        ans+=('a'+j);
    }
  }
  while(ans.size()<n)ans+=ans;
  cout<<ans.substr(0,n)<<'\n';
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