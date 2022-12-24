#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  cout<<1<<'\n';
  for(int i=2;i<=n;++i)
  {
    for(int j=1;j<=i;++j)
    {
        if(j==1||j==i)
        {
            cout<<1<<' ';
        }
        else
        {
            cout<<0<<' ';
        }
    }
    cout<<'\n';
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