/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
      int l = 0, r = nums.size() - 1, m;
      while (l <= r) {
        m = (l + r) >> 1;
        if (nums[m] < nums[r]) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      return nums[m];
    }
};
// @lc code=end

