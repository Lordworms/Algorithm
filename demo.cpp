#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1000000007;
using i64 = long long;
// assume -P <= x < 2P
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
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

constexpr int N = 4E6;

std::vector<Z> fac(N + 1), invfac(N + 1);

Z binom(int n, int m) {
    if (n < m || m < 0) {
        return 0;
    }
    return fac[n] * invfac[m] * invfac[n - m];
}

Z work(std::vector<int> p) {
    const int n = p.size();
    Z ans = 0;
    
    for (int t = 0; t < 2; t++) {
        std::vector dp(n, std::vector<Z>(n));
        for (int i = t; i < n; i += 2) {
            dp[i][i] = (p[i] == 0 || p[i] == -1);
        }
        
        for (int i = n - 1 - (n % 2 == t); i >= 0; i -= 2) {
            int x = 0;
            for (int j = i; j < n; j += 2) {
                x++;
                if (i > j) {
                    continue;
                }
                int k = i < 2 ? !t : i - 2;
                if (x >= n - 1 && (p[k] == -1 || p[k] == n - 1)) {
                    ans += dp[i][j];
                    continue;
                }
                if (p[k] == -1 || p[k] == x) {
                    dp[k][j] += dp[i][j];
                }
                k = j + 2 >= n ? n - 1 - (n % 2 == !t) : j + 2;
                if (p[k] == -1 || p[k] == x) {
                    dp[i][k] += dp[i][j];
                }
            }
            for (int j = n - 1 - (n % 2 == !t); j >= 0; j -= 2) {
                x++;
                if (i > j) {
                    continue;
                }
                if (x >= n - 1 && j >= 2 && (p[j - 2] == -1 || p[j - 2] == n - 1)) {
                    ans += dp[i][j];
                    continue;
                }
                int k = i < 2 ? !t : i - 2;
                if (p[k] == -1 || p[k] == x) {
                    dp[k][j] += dp[i][j];
                }
                if (j >= 2) {
                    k = j - 2;
                    if (p[k] == -1 || p[k] == x) {
                        dp[i][k] += dp[i][j];
                    }
                }
            }
        }
        for (int i = !t; i < n; i += 2) {
            int x = i / 2 + 1;
            for (int j = t; j < n; j += 2) {
                x++;
                if (i > j) {
                    continue;
                }
                if (x >= n - 1 && i + 2 < n && (p[i + 2] == -1 || p[i + 2] == n - 1)) {
                    ans += dp[i][j];
                    continue;
                }
                int k;
                if (i + 2 < n) {
                    k = i + 2;
                    if (p[k] == -1 || p[k] == x) {
                        dp[k][j] += dp[i][j];
                    }
                }
                k = j + 2 >= n ? n - 1 - (n % 2 == !t) : j + 2;
                if (p[k] == -1 || p[k] == x) {
                    dp[i][k] += dp[i][j];
                }
            }
            for (int j = n - 1 - (n % 2 == !t); j > i; j -= 2) {
                x++;
                if (i > j) {
                    continue;
                }
                if (x >= n - 1 && i + 2 < n && (p[i + 2] == -1 || p[i + 2] == n - 1)) {
                    ans += dp[i][j];
                    continue;
                }
                int k;
                if (i + 2 < n) {
                    k = i + 2;
                    if (p[k] == -1 || p[k] == x) {
                        dp[k][j] += dp[i][j];
                    }
                }
                if (j >= 2) {
                    k = j - 2;
                    if (p[k] == -1 || p[k] == x) {
                        dp[i][k] += dp[i][j];
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         std::cerr << dp[i][j] << " \n"[j == n - 1];
        //     }
        // }
    }
    
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        if (p[i] != -1) {
            p[i]--;
        }
    }
    
    auto ans = work(p);
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[N] = fac[N].inv();
    for (int i = N; i; i--) {
        invfac[i - 1] = invfac[i] * i;
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}