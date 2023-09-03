#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n;
  vector<vector<int>> album(n);
  map<int, vector<int>> index;
  function<vector<int>(vector<int>&)> compress = [&](vector<int>& a) {
    vector<int> new_a;
    int maxx = -1;
    for (int &v : a) {
      if (v > maxx) {
        new_a.emplace_back(v);
        maxx = v;
      }
    }
    return new_a;
  };
  for (int i = 0; i < n; ++i) {
    cin >> k;
    album[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> album[i][j];
    }
    album[i] = compress(album[i]);
  } 
  for (int i = 0; i < n; ++i) {
    for (int &v : album[i]) {
      index[v].push_back(i);
    }
  }
  vector<int> dp(n); // the maximum impression could get if end with the ith album
  int end = 0, c;
  for (auto& pi : index) {
    int cur_end = 0;
    c = pi.first;
    for (int &v : pi.second) {
      if (c == album[v].back()) {
        dp[v] = max(dp[v] + 1, end + 1);
        cur_end = max(cur_end, dp[v]);
        continue;
      } 
      if (c == album[v].front()) {
        dp[v] = end + 1;
        continue;
      }
      dp[v] = max(dp[v] + 1, end + 1); // in other situation, plus one!
    }
    end = max(end, cur_end);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef DEBUG
  freopen("/Users/yanxinxiang/code/Algorithm/in", "r", stdin);
  freopen("/Users/yanxinxiang/code/Algorithm/out", "w", stdout);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}