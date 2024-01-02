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
      int n = nums.size();
      int cur_sum = 0;
      int ans = nums[0];
      for (int i = 0; i < n; ++i) {
        // two options: get the new one and abandon the previous element or starting the new one
        cur_sum = max(cur_sum + nums[i], nums[i]);
        ans = max(ans, cur_sum);
      }
      return ans;
    }
};
// @lc code=end

