/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& p) {
      int ans = 0, minx = INT_MAX;
      for (int i = 0; i < p.size(); ++i) {
        minx = min(minx, p[i]);
        ans = max(ans, p[i] - minx);    
      }
      return ans;
    }
};
// @lc code=end

