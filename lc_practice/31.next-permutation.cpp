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
    int n = nums.size();
    int i = n - 1, j = -1;
    /* find the first position which holds a nums[i] > nums[i - 1] since this
     * position is the position which we should reverse
     * then we could find the first element which is greater than j, then swap them
     * 1 3 6 5 4 - > 1 4 3 5 6
     */
    for (i = n - 1; i >= 1; --i) {
      if (nums[i] > nums[i - 1]) {
        j = i - 1;
        break;
      }
    }
    if (j >= 0) {
      for (int k = n - 1; k >= 0; --k) {
        if (nums[k] > nums[j]) {
          swap(nums[j], nums[k]);
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
//   vector<int> a = {3, 2, 1};
//   sol.nextPermutation(a);
//   return 0;
// }
