#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
struct Seg {
	ll init_x, init_y;
	int num;
	ld x, y;
	Seg() {}
	Seg(int p, int q, int num): init_x(q), init_y(-p), num(num) {
		x = init_x;
		y = init_y;
	}
 
	friend bool operator<(const Seg &s1, const Seg &s2) {
		if (s1.init_x * s2.init_y == s1.init_y * s2.init_x)
			return s1.num < s2.num;
		return s1.init_x * s2.init_y < s1.init_y * s2.init_x;
	}
	Seg operator*=(ld ratio) { x *= ratio; y *= ratio; return *this; }
 
	void show() {
		cout << "Seg(" << x << ' ' << y << ")";
	}
};
struct Point {
	ld x, y;
	Point() {}
	Point(int a, int b): x(b), y(a) {}
	Point operator+=(const Point &v) { x += v.x; y += v.y; return *this; }
    Point operator-=(const Point &v) { x -= v.x; y -= v.y; return *this; }
	Point operator+=(const Seg &v) { x += v.x; y += v.y; return *this; }
    Point operator-=(const Seg &v) { x -= v.x; y -= v.y; return *this; }
 
	void show() {
		cout << "Point(" << x << ' ' << y << ")";
	}
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}