/**
 first, there always exist a perfect array
 pre: 
    for all n
    n<=(sqrt(n))^2<=2*n
    let k be the greatest number k^2<=n
    for k>=3 k^2-2*k-1>=0
    so n<=(k+1)^2=k^2+2*k+1<=n+k^2<=2*n
    so we could always find a 根号n的下界+1的平方满足要求
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
  function<void(int)>fill=[&](int r)
  {
    if(r<0)return;
    int s=sqrt(2*r);s*=s;
    int l=s-r;fill(l-1);
    for(;l<=r;++l,--r)
    {
        a[l]=r,a[r]=l;
    }
  };
  fill(n-1);
  for(int i=0;i<n;++i)
  {
    cout<<a[i]<<" \n"[i==n-1];
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