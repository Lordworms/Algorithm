/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size(), cur_sum = 0, ans = INT_MIN;
      for (int i = 0; i < n; ++i) {
        cur_sum = max(cur_sum + nums[i], nums[i]);
        ans = max(cur_sum, ans);
      }
      return ans;
    }
};
// @lc code=end

