#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<unordered_map>
#include<stack>
#include<math.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<deque>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lowbits(x) x&(-x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 2e5 + 10;
ll exgcd(ll a, ll b, ll& x, ll& y){
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
int main() {
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
    ll x, y;
    ll gcd=exgcd(w, d, x, y);
    w = w / gcd;
    ll ans = (y % w) * (p / gcd % w) % w;
    while (ans < 0) {
        ans += w;
    }
    w = w * gcd;
    y = ans;
    x = (p - d * y) / w;
    if (p % gcd != 0) {
        x = -1;
    }
    if (x < 0 || y<0 || x + y>n) {
        cout << -1 << endl;
    }
    else {
        cout << x << " " << y << " " << n - x - y << endl;
    }
    return 0;
}