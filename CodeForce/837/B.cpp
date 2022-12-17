/*
  we could first get the most right stranger to a certain one then we could
  iterate the array and using the current start. because for every i in a consecutive array, the contribution of each element is i-cur
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int>L(n+1,0);
  for(int i=0;i<m;++i)
  {
    int x,y;
    cin>>x>>y;
    if(x>y)swap(x,y);
    L[y]=max(L[y],x);
  }
  int cur=0;
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    cur=max(L[i],cur);
    ans+=i-cur;
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