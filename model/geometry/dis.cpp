#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}