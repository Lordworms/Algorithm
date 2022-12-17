#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  if(n==1)
  {
    cout<<1<<'\n';
    cout<<1<<' '<<2<<'\n';
    return;
  }
  int lim;
  if(n%2)
  {
    cout<<n/2+1<<'\n';
  }
  else
  {
    cout<<n/2<<'\n';
  }
  int st=1,ed=3*n-1;
  for(int i=0;i<n/2;++i)
  {
    cout<<st<<' '<<ed<<'\n';
    st+=3;
    ed-=3;
  }
  if(n%2)
  {
    cout<<3*n/2<<' '<<3*n/2+1<<'\n';
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