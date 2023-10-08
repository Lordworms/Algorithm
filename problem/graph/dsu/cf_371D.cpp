#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 2e5 + 50;
const int inf = 0x3f3f3f3f;
int a[N], fa[N], v[N];
int n, q;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  int t1 = find(x);
  int t2 = find(y);
  fa[t1] = t2;
}
void init() {
  for (int i = 1; i <= n + 2; i++) {
    fa[i] = i;
  }
}
int main() {
  n = read();
  init();
  for (int i = 1; i <= n; i++) {
    v[i] = read();
  }
  memset(a, 0, sizeof a);
  q = read();
  while (q--) {
    int op;
    op = read();
    if (op == 1) {
      int k, c;
      k = read();
      c = read();
      while (c) {
        k = find(k);
        if (k > n) {
          break;
        }
        if (a[k] + c >= v[k]) {
          c -= (v[k] - a[k]);
          a[k] = v[k];
          merge(k, k + 1);
        } else {
          a[k] += c;
          c = 0;
        }
      }
    } else {
      int k;
      k = read();
      cout << a[k] << endl;
    }
  }
  return 0;
}