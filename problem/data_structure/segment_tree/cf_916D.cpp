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
int rt1[MAXN << 5], rt2[MAXN << 5];
const int lim = 1e9;
unordered_map<string, int> st;
void push_up(int c) {
  tr[c].v = tr[tr[c].l].v + tr[tr[c].r].v;
}
int cnts, cnt;
// get the id of the incomming name
ll getid(string s) {
  return st.find(s) == st.end()? st[s] = ++cnts : st[s];
}
// update the position by add 
int update(int l, int r, int pos, ll add, int rt) {
  int cur = ++cnt;
  // set to the same in the first iteration and then do the modification one by one
  tr[cur].l = tr[rt].l, tr[cur].r = tr[rt].r;
  if (l == r) {
    tr[cur].v = tr[rt].v + add;
    return cur;
  }
  int m = (l + r) >> 1;
  if (pos <= m) {
    /// warning! this should use tr[rt].l since we should know the original setting of previous layout
    tr[cur].l = update(l, m, pos, add, tr[rt].l);
  } else {
    tr[cur].r = update(m + 1, r, pos, add, tr[rt].r);
  }
  push_up(cur);
  return cur;
}
// inline ll update(ll l, ll r, ll pos, ll val, ll node)
// {
//   ll cur = ++cnt;
//   tr[cur].l = tr[node].l, tr[cur].r = tr[node].r;
//   if (l == r)
//   {
//     return tr[cur].v = tr[node].v + val, cur;
//   }
//   ll mid = (l + r) >> 1;
//   if (pos <= mid)
//   {
//     tr[cur].l = update(l, mid, pos, val, tr[node].l);
//     //ls[cur] = update(l, mid, pos, val, ls[node]);
//   }
//   else
//   {
//     //rs[cur] = update(mid + 1, r, pos, val, rs[node]);
//     tr[cur].r = update(mid + 1, r, pos, val, tr[node].r);
//   }
//   return push_up(cur), cur;
// }
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
// inline ll query(ll l, ll r, ll ql, ll qr, ll node)
// {
//   if (ql <= l && qr >= r)
//   {
//     return tr[node].v;
//   }
//   ll mid = (l + r) >> 1, res = 0;
//   res += ql <= mid ? query(l, mid, ql, qr, tr[node].l) : 0;
//   res += qr > mid ? query(mid + 1, r, ql, qr, tr[node].r) : 0;
//   return res;
// }
void solve() {
  int n, id, pri, times, pre;
  string name;
  cin >> n;
  string op;
  for (int i = 1; i <= n; ++i) {
    cin >> op;
    rt1[i] = rt1[i - 1], rt2[i] = rt2[i - 1];
    if (op == "set") {
      // cin >> name >> pri;
      // id = getid(name);
      // // check previous priority
      // pre = query(1, lim, id, id, rt2[i]);
      // // previously has one
      // if (pre) {
      //   rt1[i] = update(1, lim, pre, -1, rt1[i]);
      // } else { // previously did not has one
      //   rt1[i] = 1;
      // }
      // // add the priority by one
      // rt1[i] = update(1, lim, pri, 1, rt1[i]); // rt 1 reserve the priority set (pri->cnt have this priority or not)
      // // add the priority of current by pri - pre <=> equals to pri finally
      // rt2[i] = update(1, lim, id, pri - pre, rt2[i]); // rt2 (id -> pri)
      cin >> name >> pri; id = getid(name), pre = query(1, lim, id, id, rt2[i]);
      pre ? rt1[i] = update(1, lim, pre, -1, rt1[i]) : 1;
      rt1[i] = update(1, lim, pri, 1, rt1[i]), rt2[i] = update(1, lim, id, pri - pre, rt2[i]);
    }
    if (op == "remove") {
      cin >> name;
      id = getid(name);
      // same logic
      pri = query(1, lim, id, id, rt2[i]);
      pri? rt1[i] = update(1, lim, id, -1, rt1[i]) : 1;
      rt2[i] = update(1, lim, id, -pri, rt2[i]);
    }
    if (op == "undo") {
      cin >> times;
      rt1[i] = rt1[i - times - 1];
      rt2[i] = rt2[i - times - 1];
    }
    if (op == "query") {
      cin >> name;
      id = getid(name);
      pri = query(1, lim, id, id, rt2[i]);
      cout << ((pri == 0 || pri == 1) ? pri - 1 : query(1, lim, 1, pri - 1, rt1[i])) << '\n';
    }
  }
  return;
}
int main() {
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