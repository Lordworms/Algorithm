/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int largestRectangleArea(vector<int>& h) {
    int n = h.size();
    vector<int> left(n, -1), right(n, n), st;
    for (int i = 0; i < n; ++i) {
      while (st.size() && h[st.back()] >= h[i]) st.pop_back();
      if (st.size()) {
        left[i] = st.back();
      }
      st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (st.size() && h[st.back()] >= h[i]) st.pop_back();
      if (st.size()) {
        right[i] = st.back();
      }
      st.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, (right[i] - left[i] - 1) * h[i]);
    }
    return ans;
  }
};
// @lc code=end
int main() {
  vector<int> a = {0, 9};
  Solution sol;
  assert(sol.largestRectangleArea(a) == 10);
}
