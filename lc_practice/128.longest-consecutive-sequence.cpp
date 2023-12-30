/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      map<int, int> mp;
      int ans = 1;
      if (nums.size() == 0) ans = 0;
      sort(nums.begin(), nums.end());
      for (auto &num : nums) {
        mp[num] = max(mp[num - 1] + 1, mp[num]);
        ans = max(mp[num], ans);  
      }
      return ans;
    }
};
// @lc code=end

