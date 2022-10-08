/*
                                        select      canbe
    1 2 3                       1        1 2 3      1x1 1x2 1x3
    4 5 6 7 8                   2        4 6 8      2x2 2x3 2x4
    9 10 11 12 13 14 15         3        9 12 15    3x3 3x4 3x5
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll get(ll x){
    ll ans=0;
    for(int j=0;j<=2;++j)
    {
        ll l=0,r=1e10,m;
        while(l+1!=r)
        {
            m=(l+r)>>1;
            if(m*(m+j)>x)
            {
                r=m;
            }
            else l=m;
        }
        ans+=l;
    }
    return ans;
}
void solve()
{
    ll l,r;
    cin>>l>>r;
    cout<<get(r)-get(l-1)<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}