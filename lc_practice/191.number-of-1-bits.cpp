/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int ans = 0;
      while(n) {
        if (n & 1) ++ans;
        n >>= 1;
      }    
      return ans;
    }
};
// @lc code=end

