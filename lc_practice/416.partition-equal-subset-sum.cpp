/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
      }
      if (sum % 2) {
        return false;
      }
      vector<int> dp((sum >> 1) + 1, 0);
      dp[0] = true;
      for (int i = 0; i < nums.size(); ++i) {
        for (int v = sum >> 1; v >= nums[i]; --v) {
          dp[v] |= dp[v - nums[i]];
        }  
      }
      return dp[sum / 2];
    }
};
//@lc code=end
// int main() {
//   vector<int> a = {1,5,11,5};
//   Solution sol;
//   sol.canPartition(a);
// }

