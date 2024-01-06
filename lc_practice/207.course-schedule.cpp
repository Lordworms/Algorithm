/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
      vector<int> deg(n);
      vector<vector<int>> E(n);
      for (const auto &p : pre) {
        deg[p[0]]++;
        E[p[1]].push_back(p[0]);
      }
      queue<int> q;
      for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
          q.push(i);
        }
      }
      while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto &v : E[x]) {
          deg[v]--;
          if (!deg[v]) {
            q.push(v);
          }  
        }
      }
      for (int i = 0; i < n; ++i) {
        if (deg[i]) return false;
      }
      return true;
    }
};
// @lc code=end

