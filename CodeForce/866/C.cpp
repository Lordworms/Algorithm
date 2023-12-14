#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
template<class T>
int GetMex(vector<T> arr) {
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] != i) {
      return i;
    }
  }
  return arr.size();
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> left, right;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    right[a[i]] = i;
    if (!left.count(a[i])) {
      left[a[i]] = i;
    }
  }
  int mex = GetMex(a);
  // first if get a position which euqals to mex + 1
  if (left.count(mex + 1)) {
    int L = left[mex + 1], R = right[mex + 1];
    for (int i = L; i <= R; ++i) {
      a[i] = mex;
    }
    int tmp = GetMex(a);
    // could apply
    if (tmp == mex + 1) {
      cout << "YES" << '\n';
      return;
    } else { //could not since we have a smallar between that shit
      cout << "NO" << '\n';
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > mex || left[a[i]] != right[a[i]]) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
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
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}