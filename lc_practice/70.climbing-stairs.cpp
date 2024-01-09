/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start

class Solution {
public:
    int climbStairs(int n) {
      int d1 = 1, d2 = 2;
      if (n == 1) return d1;
      if (n == 2) return d2;
      for (int i = 3; i <= n; ++i) {
        int tmp = d2;
        d2 = d1 + d2;
        d1 = tmp;    
      }  
      return d2;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.climbStairs(3);
// }
