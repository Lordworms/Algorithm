/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      int l = 0, r = n - 1;
      bool find = false;
      vector<int> ans;
      if (nums.size() == 0 || *nums.begin() > target || nums.back() < target) {
        ans = {-1, -1};
        return ans;
      }
      // find the first position
      while (l <= r) {
        int m = (l + r) >> 1;
        if (nums[m] == target) {
          find = true;  
        }
        if (nums[m] > target) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      ans.push_back(r);
      l = 0, r = n - 1;
      // find the last position
      while (l <= r) {
        int m = (l + r) >> 1;
        if (nums[m] < target) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      ans.push_back(l);
      swap(ans[0], ans[1]);
      if (!find) {
        ans = {-1, -1};
      }
      return ans;
    }
};
// @lc code=end
int main() {
  vector<int> a = {5,7,7,8,8,10};
  Solution sol;
  sol.searchRange(a, 8);
}
