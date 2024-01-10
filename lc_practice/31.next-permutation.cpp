/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int i = 0, j = 0, n = nums.size();
      for (i = n - 1; i > 0; --i) {
        if (nums[i] > nums[i - 1]) {
          j = i - 1;
          break;
        }
      }
      if (j >= 0) {
        // not the last permutation
        for (int k = n - 1; k >= 0; --k) {
          if (nums[k] > nums[j]) {
            swap(nums[k], nums[j]);
            break;
          }
        }
      }
      reverse(nums.begin() + i, nums.end());
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {1,3,2};
//   sol.nextPermutation(a);
//   return 0;
// }
