/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      map<int, int> mp;
      int s = 0, ans = 0;
      for (int i = 0; i < nums.size(); ++i) {
        mp[s]++;    
        s += nums[i];
        ans += mp[s - k];
      }
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  vector<int> nums = {1, 1, 1};
  sol.subarraySum(nums, 2);
  return 0;
}
