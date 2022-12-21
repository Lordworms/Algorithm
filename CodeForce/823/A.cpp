#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  unordered_map<int,int>st;
  int n,c;
  cin>>n>>c;
  ll ans=0;
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    st[x]++;
  }
  for(auto &k:st)
  {
    auto num=k.second;
    ans+=num<c?num:c;
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