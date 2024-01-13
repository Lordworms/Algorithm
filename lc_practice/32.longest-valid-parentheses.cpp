/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestValidParentheses(string s) {
    vector<int> st;
    st.push_back(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push_back(i);
      } else {
        st.pop_back();
        if (st.size() == 0) {
          st.push_back(i);
        } else {
          ans = max(ans, i - st.back());
        }
      }
    }
    return ans;
  }
};
// @lc code=end
int main() {
  Solution sol;
  assert(sol.longestValidParentheses("(()") == 2);
}
