/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
/* classic sliding window */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> last_pos;
      int beg = 0;
      int n = s.size(), len, ans = 0;
      for (int i = 0; i < n; ++i) {
        if (last_pos.find(s[i]) != last_pos.end()) {
          beg = std::max(beg, last_pos[s[i]] + 1);
        } 
        last_pos[s[i]] = i;
        ans = max(ans, i - beg + 1);   
      }
      return ans;
    }
};
// @lc code=end

