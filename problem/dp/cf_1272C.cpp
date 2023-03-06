#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;cin>>n>>k;
  string s;cin>>s;
  ll ans=0;
  unordered_set<char>st;
  for(int i=0;i<k;++i)
  {
    char c;cin>>c;
    st.insert(c);
  }
  int l=0,r=0;
  while(r<n)
  {
    while(r<n&&st.count(s[r]))++r;
    ll len=r-l;
    ans+=(len+1)*len/2;
    ++r;
    l=r;
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}