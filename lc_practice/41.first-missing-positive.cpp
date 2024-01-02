/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]) {
          swap(nums[i], nums[nums[i] - 1]);
        }
      }
      for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
          return i + 1;
        }
      }
      return n + 1;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> nums = {7,8,9,11,12};
//   assert(sol.firstMissingPositive(nums) == 2);
// }

