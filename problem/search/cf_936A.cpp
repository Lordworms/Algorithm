/*
    (k-1)/d+1表示向上取整
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  ll k,d,t;
  cin>>k>>d>>t;
  ll T=((k-1)/d+1)*d;//一个周期多久 开->关为一个周期
  double one_t=(T-k)*0.5+k;//一个周期能烤熟多少
  double ans=0;
  ans+=ll(t/one_t)*T;//需要多少个完整周期
  ll ht=t/one_t;//需要多少个完整周期（没算小数点后面的）
  double rem=t-ht*one_t;
  if(rem<k)//加上即可
  {
    ans+=rem;
  }
  else
  {
    ans+=k+(rem-k)*2;
  }
  cout<<fixed<<ans<<'\n';
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