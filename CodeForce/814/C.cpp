#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<int>a(n+1),cnt(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  int now=1;
  for(int i=2;i<=n;++i)
  {
    if(a[now]<a[i])
    {
        now=i;
    }
    cnt[now]++;
  }
  int k;
  for(int i=0;i<q;++i)
  {
    cin>>now>>k;
    k-=max(0,now-2);
    k=max(k,0);
    if(a[now]==n)
    {
        cout<<k<<'\n';
    }
    else
    {
        cout<<min(k,cnt[now])<<'\n';
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