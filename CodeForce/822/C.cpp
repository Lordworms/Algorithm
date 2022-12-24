#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  string s;
  int n;
  cin>>n>>s;
  s.insert(0,1,'0');
  vector<int>carry(n+1,0);
  vector<int>cost(n+1,0);
  for(int i=1;i<=n;++i)
  {
    carry[i]=s[i]=='1';
  }
  for(int i=n;i>=1;--i)
  {
    for(int j=i;j<=n;j+=i)
    {
        if(carry[j])break;
        cost[j]=i;
    }
  }
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    if(!carry[i])ans+=cost[i];
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