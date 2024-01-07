/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<pair<int, int>> cur_q;
      auto check = [&] (int x, int y) {
        for (auto &p : cur_q) {
          if (x == p.first || y == p.second || abs(x - p.first) == abs(y - p.second)) {
            return false;
          }    
        }
        return true;
      };
      auto push_ans = [&]() {
        vector<string> cur_pat;
        for (int i = 0; i < cur_q.size(); ++i) {
          string cur_line;  
          for (int j = 0; j < n; ++j) {
            if (cur_q[i].second == j) {
              cur_line.push_back('Q');
            } else {
              cur_line.push_back('.');
            }
          }
          cur_pat.push_back(cur_line);
        }
        ans.push_back(cur_pat);  
      };
      function<void(int)> dfs = [&] (int cur) {
        if (cur == n) {
          push_ans();
          return;  
        }    
        for (int i = 0; i < n; ++i) {
          if (check(cur, i)) {
            cur_q.push_back({cur, i});
            dfs(cur + 1);
            cur_q.pop_back();
          }
        }
      };
      dfs(0);
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  sol.solveNQueens(4);
}

