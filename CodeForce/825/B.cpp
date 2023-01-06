#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=1;i<n-1;++i)
  {
    if(gcd(a[i-1],a[i+1])!=gcd(gcd(a[i-1],a[i]),gcd(a[i],a[i+1])))
    {
        cout<<"NO"<<'\n';
        return;
    }
  }
  cout<<"YES"<<'\n';
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