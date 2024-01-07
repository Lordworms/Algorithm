/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1, ans = target > nums.back() ? nums.size() : 0;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (nums[m] >= target) {
          r = m - 1;  
          ans = m;
        } else {
          l = m + 1;
        }
      }
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  vector<int> a = {1, 3, 5, 6};
  sol.searchInsert(a, 5);
}
