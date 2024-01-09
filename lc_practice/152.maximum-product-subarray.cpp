/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      int ans = nums[0], maxF = nums[0], minF = nums[0];
      for (int i = 1; i < n; ++i) {
        int tmp = maxF;
        maxF = max(maxF * nums[i], max(nums[i], minF * nums[i]));
        minF = min(minF * nums[i], min(nums[i], tmp * nums[i]));
        ans = max(ans, maxF);      
      }   
      return ans;  
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {-4,-3,-2};
//   sol.maxProduct(a);
// }
