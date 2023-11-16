#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 2e5 + 10;
struct node {
  int l, r;
  ll v;
};
node tr[MAXN << 5];
unordered_map<string, int> st;
void push_up(int c) {
  tr[c].v = tr[tr[c].l].v + tr[tr[c].r].v;
}
int cnts, cnt;
ll getid(string s) {
  return st.find(s) != st.end()? st[s] = ++cnts : st[s];
}
int update(int l, int r, int pos, ll add, int rt) {
  int cur = ++cnt;
  tr[cur].l = tr[rt].l, tr[cur].r = tr[rt].r;
  if (l == r) {
    tr[cur].v = tr[rt].v + add;
    return cur;
  }
  int m = (l + r) >> 1;
  if (pos <= m) {
    tr[cur].l = update(l, m, pos, add, tr[cur].l);
  } else {
    tr[cur].r = update(m + 1, r, pos, add, tr[cur].r);
  }
  push_up(cur);
  return cur;
}
ll query(int l, int r, int ql, int qr, int rt) {
  if (ql <= l && qr >= r) {
    return tr[rt].v;
  }
  int m = (l + r) >> 1;
  ll res = 0;
  if (ql <= m) {
    res += query(l, m, ql, qr, tr[rt].l);
  }
  if (qr > m) {
    res += query(m + 1, r, ql, qr, tr[rt].r);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  string op;
  for (int i = 1; i <= n; ++i) {
    cin >> op;
    if (op == "set") {

    }
    if (op == "remove") {

    }
    if (op == "undo") {

    }
    if (op == "query") {
        
    }
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