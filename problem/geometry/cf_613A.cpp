#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  bool operator == (const Point &a) const { 
    return x == a.x && y == a.y;
  }
  Point operator - (const Point &a) const {
    return Point(x - a.x, y - a.y);
  }
};
double Dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y; 
}
double Length(const Point &a) {
  return sqrt(Dot(a, a));
}
// area of two vector
double Cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
double Dis(const Point &a, const Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double DirDisToSeg(const Point &p, const Point &a, const Point &b) {
  if (a == b) {
    return Dis(a, p);
  }
  Point v1, v2, v3;
  v1 = b - a;
  v2 = p - a;
  v3 = p - b;
  if (Dot(v1, v2) < 0) return Length(v2);
  if (Dot(v1, v3) > 0) return Length(v3);
  return fabs(Cross(v1, v2)) / Length(v1);
}
void solve() {
  int n;
  Point p0;
  cin >> n >> p0.x >> p0.y;
  double min_dis = 1e18, max_dis = 0;
  vector<Point> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  a[n].x = a[0].x;
  a[n].y = a[0].y;
  for (int i = 0; i < n; ++i) {
    double d1 =  Dis(p0, a[i]), d2 = DirDisToSeg(p0, a[i], a[i + 1]);
    //cout << "d1:" << d1 << '\n' << "d2:" << d2 << '\n';
    max_dis = max(max_dis, d1);
    //std::cout << "max_dis:" << max_dis << '\n';
    min_dis = min(min_dis, d2);
    //std::cout << "min_dis:" << min_dis << '\n';
  }
  cout.precision(10);
  cout << max_dis * max_dis * pi - min_dis * min_dis * pi << '\n';
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("D:/code/Algorithm/in", "r", stdin);
  // freopen("D:/code/Algorithm/out", "w", stdout);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}