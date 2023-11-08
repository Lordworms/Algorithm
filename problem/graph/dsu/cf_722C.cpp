#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
int fa[MAXN], a[MAXN];
ll sum[MAXN];
bool ok[MAXN];
ll ans;
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);  
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
    sum[y] += sum[x];
    ans = max(ans, sum[y]);
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    fa[i] = i;
  } 
  vector<int> op(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> op[i];
  }
  vector<int> res(n + 1);
  for (int i = n; i >= 1; --i) {
    sum[op[i]] = a[op[i]];
    ok[op[i]] = 1;
    ans = max(ans, sum[op[i]]);
    if (ok[op[i] + 1] != 0) {
      merge(op[i], op[i] + 1);  
    } 
    if (ok[op[i] - 1] != 0) {
      merge(op[i], op[i] - 1);
    }  
    res[i] = ans;
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << '\n'
  }
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
//#ifdef DEBUG
  freopen("D:/code/Algorithm/in", "r", stdin);
  freopen("D:/code/Algorithm/out", "w", stdout);
//#endif
  int T = 1;
  while (T--) {
    
    solve();
  }
  return 0;
}