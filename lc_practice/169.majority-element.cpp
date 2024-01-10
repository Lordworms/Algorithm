/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int candidate = nums[0], cnt = 1;
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == candidate) {
          ++cnt;
        } else if (--cnt < 0) {
          candidate = nums[i];
          cnt = 0;
        }
      }
      return candidate;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {3,2,3};
//   sol.majorityElement(a);
// }
