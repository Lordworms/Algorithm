/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> ans;
      map<int, int> pos;
      int end = 0, start = 0;
      for (int i = 0; i < s.size(); ++i) {
        pos[s[i]] = i;
      }
      for (int i = 0; i < s.size(); ++i) {
        end = max(end, pos[s[i]]);
        if (i == end) {
          ans.push_back(end - start + 1);
          start = end + 1;
        }
      }
      return ans;
    }
};
// @lc code=end

