/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans;
      if (s.size() < p.size()) {
        return ans;
      }
      map<char, int> cur, stand;
      for (auto &c : p) {
        stand[c]++;
      }
      auto check = [&] () {
        for (auto &k : stand) {
          if (cur[k.first] != k.second) return false;
        }
        return true;
      };
      for (int i = 0; i < p.size(); ++i) {
        cur[s[i]]++;    
      }
      if (check()) {
        ans.push_back(0);
      }
      for (int i = p.size(); i < s.size(); ++i) {
        cur[s[i - p.size()]]--;
        cur[s[i]]++;
        if (check()) {
          ans.push_back(i - p.size() + 1);
        }  
      }
      return ans;
    }
};
// @lc code=end

