#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int MOD=1e9+7;
ll n,L;
struct BLine
{
  struct Point
  {
    int x,y,id;
    Point(int xx,int yy,int idd):x(xx),y(yy),id(idd){}
    double cal(Point p)//calc slope
    {
      double dy=p.y-y;
      double dx=p.x-x;
      return dy/dx;
    }
    ll value(ll k)
    {
      return k*x+y;
    }
  };
  const ll INF=1e16;
  vector<long double>slopes;
  vector<Point>points;
  BLine()
  {
    slopes.push_back(-INF);
    points.push_back(Point(0,L*L,0));
  }
  void add(Point p)
  {
    while(points.size()>=2&&p.cal(points[points.size()-1])<=slopes.back())
    {
      points.pop_back();
      slopes.pop_back();
    }
    if(!points.empty())slopes.push_back(p.cal(points.back()));
    points.push_back(p);
  }
  ll query(ll k)
  {
    int id=upper_bound(slopes.begin(),slopes.end(),k)-slopes.begin();// id in points
    --id;
    return points[id].id;
  }
};
void solve()
{
  cin>>n>>L;
  ++L;
  vector<ll>a(n+1),sum(n+1),dp(n+1);
  BLine bl;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    sum[i]=sum[i-1]+a[i]+1;
  }
  int id;
  for(int i=1;i<=n;++i)
  {
    int id=bl.query(2*sum[i]);
    dp[i]=dp[id]+(sum[i]-sum[id]-L)*(sum[i]-sum[id]-L);
    bl.add(BLine::Point(sum[i],dp[i]+(sum[i]+L)*(sum[i]+L),i));
  }
  cout<<dp[n]<<'\n';
  return;
}
signed main()
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