#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> mp;
      vector<int> res;
      for (int i = 0; i < nums.size(); ++i) {
        if (mp.find(target - nums[i]) != mp.end()) {
          res = {i, mp[target - nums[i]]};
          break;
        }
        mp[nums[i]] = i;
      }  
      return res;
    }
};
// @lc code=end

