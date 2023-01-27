#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string t,s;
  int n,k;
  cin>>n>>k>>s;
  t=s;
  for(int i=k;i<n;++i)
  {
    t[i]=t[i-k];
  }
  if(t<s)
  {
    int p=k-1;
    while(t[p]=='9'&&p)
    {
        t[p]='0';
        --p;
    }
    t[p]++;
  }
  for(int i=k;i<n;++i)
  {
    t[i]=t[i-k];
  }
  cout<<n<<'\n'<<t<<'\n';
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