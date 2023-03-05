#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int a,b;
  cin>>a>>b;
  string ans;
  for(int i=0;i<min(a,b);++i)
  {
    ans+='0';
    ans+='1';
  }
  if(a>b)
  {
    ans+=string(a-b,'0');
  }
  else
  {
    ans+=string(b-a,'1');
  }
  cout<<ans<<'\n';
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