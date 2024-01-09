/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      vector<int> vis(n);
      vis[0] = 1;
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) break;
        for (int j = i; j <= i + nums[i] && j < n; ++j) {
          vis[j] = 1;
        }
      }  
      return vis[n - 1];
    }
};
// @lc code=end
