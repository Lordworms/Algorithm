/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      set<string> st;
      for (int i = 0; i < wordDict.size(); ++i) {
        st.insert(wordDict[i]);
      }
      vector<int> dp(s.size() + 1, false);
      int n = s.size();
      s = '(' + s;
      dp[0] = true;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1;j <= i; ++j) {
          auto str = s.substr(j, i - j + 1);
          if (!dp[i - str.size()]) {
            continue;
          }
          if (st.find(str) != st.end()) {
            dp[i] = dp[i - str.size()];
          }
        }    
      } 
      return dp[n];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<string> a = {"leet", "code"};
//   sol.wordBreak("leetcode", a);
// }
