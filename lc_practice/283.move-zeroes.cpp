/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      if (nums.size() == 0) return;
      int f = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
          nums[f++] = nums[i];
        }
      }
      for (int i = f; i < nums.size(); ++i) {
        nums[i] = 0;
      }
    }
};
// @lc code=end

