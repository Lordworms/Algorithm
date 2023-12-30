/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      /*
        i + j + k > 0
      */
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); ++i) {
        if (i && nums[i] == nums[i - 1]) continue;
        int k = nums.size() - 1;
        for (int j = i + 1; j < nums.size(); ++j) {
          if (j > i + 1 && nums[j] == nums[j - 1]) continue;
          while (j < k && nums[i] + nums[j] + nums[k] > 0) --k;
          if (j < k && nums[i] + nums[j] + nums[k] == 0) {
            ans.push_back({nums[i], nums[j], nums[k]});
          }   
        }
      }
      return ans;
    }
};
// @lc code=end

int main() {
  Solution sol;
  vector<int> a({-1, 0, 1, 2, -1, -4});
  sol.threeSum(a);
}
