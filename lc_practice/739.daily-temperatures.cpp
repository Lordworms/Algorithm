/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
      vector<int> st;
      int n = temp.size();
      vector<int> ans(n, 0);
      for (int i = temp.size() - 1; i >= 0; --i) {
        while (st.size() && temp[st.back()] <= temp[i]) {
          st.pop_back();
        }
        if (st.size()) {
          ans[i] = st.back() - i;
        }
        st.push_back(i);
      }
      return ans;
    }
};
// @lc code=end
// int main() {
//   vector<int> a = {73,74,75,71,69,72,76,73};
//   Solution sol;
//   sol.dailyTemperatures(a);
// }

