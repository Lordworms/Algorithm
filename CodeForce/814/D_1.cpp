/*
    first we should know that the time comsume is the same as doing it with length of 1 or 2 after that we could try to figure out the way
    we should do it with 2 because whatever we choose, the one operation on the 2 operator is inevitable.
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  set<int>S;
  S.insert(0);
  int suf=0;
  int ans=0;
  for(int i=0;i<n;++i)
  {
    if(S.count(a[i]^suf)||a[i]==0)//if find the suffix in the set c^b or c^a^b
    {
        S.clear(),suf=0;
    }
    else// did not find needs one more operation
    {
        S.insert(suf);
        suf^=a[i];
        ++ans;
    }
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