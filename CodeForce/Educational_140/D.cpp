#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  string s;
  int n;
  cin>>n>>s;
  int k=count(s.begin(),s.end(),'1');
  for(int i=(1<<k);i<=((1<<n)-(1<<(n-k))+1);++i)
  {
    cout<<i<<' ';
  }
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
  solve();
  return 0;
}