#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int MOD=1e9+7;
using pii=pair<db,db>;
void solve()
{
  auto dis=[&](db x1,db y1,db x2,db y2)
  {
    return sqrt(fabs(x1-x2)*fabs(x1-x2)+fabs(y1-y2)*fabs(y1-y2));
  };
  db x1,x2,y1,y2,xt,yt;
  cin>>x1>>y1>>x2>>y2>>xt>>yt;
  int n;
  cin>>n;
  vector<pii>bots(n+1);
  db sum=0;
  for(int i=1;i<=n;++i)
  {
    cin>>bots[i].first>>bots[i].second;
    sum+=2*dis(bots[i].first,bots[i].second,xt,yt);
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