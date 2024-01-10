/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
      vector<int> cnt(3, 0);
      for (const auto &c : nums) {
        cnt[c]++;
      }    
      int cur = 0;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
          nums[cur++] = i;
        }
      }
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {2,0,2,1,1,0};
//   sol.sortColors(a);
// }

