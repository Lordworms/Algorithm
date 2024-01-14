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
      int ans = INT_MIN, cur_max = 0;
      for (int i = 0; i < nums.size(); ++i) {
        cur_max = max(cur_max + nums[i], nums[i]);
        ans = max(ans, cur_max);
      }
      return ans;
    }
};
// @lc code=end

