#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1);
  int pos=1;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    if(a[i]==1)pos=i; 
  }
  int len=1;
  for(int i=pos+1;i<=n;++i)
  {
    if(a[i]==len+1)++len;
  }
  int rem=n-len;
  cout<<rem/k+(rem%k!=0)<<'\n';
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