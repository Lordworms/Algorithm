#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string, int> mp;
      vector<vector<string>> ans;
      for (auto &str : strs) {
        auto s = str;
        int id;
        sort(s.begin(), s.end());
        if (mp.find(s) != mp.end()) {
          id = mp[s];     
        } else {
          mp[s] = ans.size();
          id = mp[s];
          ans.push_back(vector<string>());
        }
        ans[id].push_back(string(str));
      }
      return ans;
    }
};
// @lc code=end

