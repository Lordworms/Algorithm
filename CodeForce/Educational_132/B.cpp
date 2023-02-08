#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  vector<ll>l(n+1),r(n+2);
  for(int i=1;i<=n-1;++i)l[i+1]=l[i]+max(0,a[i]-a[i+1]);
  for(int i=n;i>=2;--i)r[i-1]=r[i]+max(0,a[i]-a[i-1]);
  while(m--)
  {
    int s,t;
    cin>>s>>t;
    if(s>t)
    {
        cout<<r[t]-r[s]<<'\n';
    }
    else
    {
        cout<<l[t]-l[s]<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}