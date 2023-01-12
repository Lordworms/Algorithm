/*
   什么时候用斜率优化呢？
   对于形如这样的方程:
   dp[i]=max/min{a[i]*b[j]+c[i]+d[i]}
   此时由于又有i又有j，不好用单调队列优化，所以这里考虑斜率优化

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
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
    points.push_back(Point(0,0,0));
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