/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.size() == 0) return vector<string>();
    int beg = nums[0], end = beg;
    vector<string> ans;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > end + 1) {
        if (beg == end) {
          ans.push_back(to_string(beg));
        } else {
          ans.push_back(to_string(beg) + "->" + to_string(end));
        }
        beg = nums[i], end = nums[i];
      } else {
        ++end;
      }
      if (i == nums.size() - 1) {
        if (beg == end) {
          ans.push_back(to_string(beg));
        } else {
          ans.push_back(to_string(beg) + "->" + to_string(end));
        }
      }
    }
    if (ans.empty()) {
      ans.push_back(to_string(beg));
    }
    return ans;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {0, 1, 2, 4, 5, 7};
//   sol.summaryRanges(a);
// }
