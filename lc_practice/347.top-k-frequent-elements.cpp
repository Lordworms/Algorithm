/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int, int> freq;
      for (auto &c : nums) {
        freq[c]++;
      }  
      map<int, vector<int>, greater<int>> qref;
      for (auto &p : freq) {
        qref[p.second].push_back(p.first);  
      }
      vector<int> ans;
      for (auto &p : qref) {
        for (auto c : p.second) {
          ans.push_back(c);
          if (ans.size() == k) {
            return ans;
          }  
        }
      }
      return ans;
    }
};
// @lc code=end

