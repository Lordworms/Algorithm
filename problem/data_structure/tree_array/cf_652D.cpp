#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 4e5 + 10;
#define id(x) (lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1)
#define lowbit(x) (x & -x)
struct Line {
  int l, r, id;
};
int tr[MAXN];
int n;
void add(int x, int v) {
  while (x < MAXN) { // directly using MAXN is ok
    tr[x] += v;
    x += lowbit(x);
  }  
}
int sum(int x) {
  int ans = 0;
  while (x) {
    ans += tr[x];
    x -= lowbit(x);
  }
  return ans;
}
void solve() {
  cin >> n;
  vector<Line> a(n + 1);
  vector<int> nums;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
    a[i].id = i;
    nums.push_back(a[i].l);
    nums.push_back(a[i].r);
  }
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin() + 1, nums.end()), nums.end());
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i].l = id(a[i].l);
    a[i].r = id(a[i].r);
  }
  sort(a.begin() + 1, a.end(), [&](Line a, Line b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l > b.l;  
  }); 
  for (int i = 1; i <= n; ++i) {
    ans[a[i].id] = sum(a[i].r);
    add(a[i].r, 1);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << '\n';
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt", "r", stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt", "w", stdout);
#endif
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}