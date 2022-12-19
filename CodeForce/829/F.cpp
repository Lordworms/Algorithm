#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  int mid=(n+1)/2,dif=n-mid;
  if(n%2==0)++mid;
  bool flag=false;
  if(n%2)
  {
    flag=true;
    --n;
  }
  for(int i=mid;i<=n;++i)
  {
    cout<<i<<' '<<i-dif<<' ';
  }
  if(flag)cout<<(n+1);
  cout<<'\n';
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