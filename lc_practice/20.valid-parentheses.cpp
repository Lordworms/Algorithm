/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isValid(string s) {
    map<char, char> mp;
    mp['['] = ']';
    mp['{'] = '}';
    mp['('] = ')';
    vector<char> st;
    st.push_back('a');
    for (auto c : s) {
      if (mp.find(c) != mp.end()) {
        st.push_back(c);
      } else {
        auto cc = st.back();
        st.pop_back();
        if (c != mp[cc]) {
          return false;
        }
      }
    }
    return st.size() == 1;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.isValid("[");
// }
