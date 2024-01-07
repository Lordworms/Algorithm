/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int target) {
      int n = g.size(), m = g[0].size();
      int l = 0, r = n * m - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int row = mid / m;
        int col = mid % m;
        if (g[row][col] == target) {
          return true;
        }
        if (g[row][col] >= target) {
          r = mid - 1; 
        } else {
          l = mid + 1;
        }
      }  
      return false;
    }
};
// @lc code=end

