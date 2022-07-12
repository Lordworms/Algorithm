/*
本节讲解数论分块，数论分块是可以在O(根号n)的时间复杂度下解决
相应的说明文档请见ipad上的数论pdf
对应的例题为：luoPP2261
    给出正整数 n 和 k，请计算f(n,k)=西格玛i=[1,n]kmodi
    k mod i= k-i*k/i然后就可以算啦
    f(i)=i;
    注意ll的问题
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin>>n>>k;
  using ll=long long;
  int r;
  ll ans=(ll)n*k;
  for(int l=1;l<=n;l=r+1)
  {
    if(l<=k)r=min((k/(k/l)),n);
    else break;
    ans-=((ll)k/l)*((ll)l+r)*(r-l+1)/2;
  }
  cout<<ans<<endl;
  return 0;

}