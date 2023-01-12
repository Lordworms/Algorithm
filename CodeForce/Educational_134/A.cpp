#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  unordered_map<char,int>mp;
  for(int i=0;i<4;++i)
  {
    char c;
    cin>>c;
    mp[c]++;
  }
  if(mp.size()==1)
  {
    cout<<0<<'\n';
    return;
  }
  if(mp.size()==4)
  {
    cout<<3<<'\n';
    return;
  }
  if(mp.size()==2)
  {
    cout<<1<<'\n';
    return;
  }
  else
  {
    cout<<2<<'\n';
    return;
  }
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