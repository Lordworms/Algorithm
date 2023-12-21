#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXN = 3e5 + 10;
struct Trie {
  Trie *ptr[2] = {nullptr};
  int sum = 0;
};
void update(Trie* rt, int x) {
  Trie *tmp = rt;
  for (int i = 30; i >= 0; --i) {
    int bit = (x >> i) & 1;
    if (tmp->ptr[bit] == nullptr) {
      tmp->ptr[bit] = new Trie;
    }
    tmp = tmp->ptr[bit];
     tmp->sum++;
  }
}
int query(Trie* rt, int x) {
  Trie *tmp = rt;
  int res = 0;
  for (int i = 30; i >= 0; --i) {
    int bit = (x >> i) & 1;
    if (tmp->ptr[bit] == nullptr || tmp->ptr[bit]->sum == 0) {
      bit ^= 1;
      res += (1 << i); 
    }
    tmp = tmp->ptr[bit];
    tmp->sum--; //  remember to subtract in the end!
  }
  return res;  
}
void solve() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  Trie *root = new Trie;
  int x;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    update(root, x);
  }
  for (int i = 1; i <= n; ++i) {
    cout << query(root, A[i]) << " \n" [i == n];
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