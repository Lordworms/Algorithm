#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1000000007;
using i64=long long;
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct BZ {
    int x;
    BZ(int x = 0) : x(norm(x)) {}
    BZ(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    BZ operator-() const {
        return BZ(norm(P - x));
    }
    BZ inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    BZ &operator*=(const BZ &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    BZ &operator+=(const BZ &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    BZ &operator-=(const BZ &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    BZ &operator/=(const BZ &rhs) {
        return *this *= rhs.inv();
    }
    friend BZ operator*(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res *= rhs;
        return res;
    }
    friend BZ operator+(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res += rhs;
        return res;
    }
    friend BZ operator-(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res -= rhs;
        return res;
    }
    friend BZ operator/(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, BZ &a) {
        i64 v;
        is >> v;
        a = BZ(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BZ &a) {
        return os << a.val();
    }
};
constexpr int N = 4E6;
 
std::vector<BZ> fac(N + 1), invfac(N + 1);
 
BZ binom(int n, int m) {
    if (n < m || m < 0) {
        return 0;
    }
    return fac[n] * invfac[m] * invfac[n - m];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}