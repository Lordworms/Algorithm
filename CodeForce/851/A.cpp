#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>pre(n+1);
  for(int i=1;i<=n;++i)
  {
    int x;cin>>x;
    pre[i]=pre[i-1];
    pre[i]+=x==2;
  }
  for(int i=1;i<=n;++i)
  {
    if (pre[i]==pre[n]-pre[i])
    {
        cout<<i<<'\n';
        return;
    }
  }
  cout<<-1<<'\n';
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