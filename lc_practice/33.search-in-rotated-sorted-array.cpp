/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size(), l = 0, r = n - 1, ans = -1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (nums[m] == target) {
          ans = m;
          break;
        }
        if (nums[0] <= nums[m]) {
          if (nums[l] <= target && nums[m] > target) {
            r = m -1;
          } else {
            l = m + 1;
          }
        } else {
          if (target <= nums[r] && nums[m] < target) {
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
      }
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  vector<int> a = {3, 5, 1};
  sol.search(a, 3);
}

