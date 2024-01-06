/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(vector<int> &nums, int cur) {
      if (cur == nums.size() - 1) {
        ans.push_back(nums);  
        return;
      }
      for (int i = cur; i < nums.size(); ++i) {
        swap(nums[cur], nums[i]);
        dfs(nums, cur + 1);
        swap(nums[cur], nums[i]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      dfs(nums, 0);
      return ans;
    }
};
// @lc code=end

