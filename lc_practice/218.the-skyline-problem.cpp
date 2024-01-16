/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& B) {
      vector<pair<int, int>> p;
      multiset<int> height;
      for (int i = 0; i < B.size(); ++i) {
        auto &b = B[i];
        p.push_back({b[0], -b[2]});
        p.push_back({b[1], b[2]});
      }
      sort(p.begin(), p.end());
      int prev_height = 0;
      vector<vector<int>> ans;
      height.insert(0);
      for (int i = 0; i < p.size(); ++i) {
        int &h = p[i].second;
        if (h < 0) {
          height.insert(-h);
        } else {
          height.erase(height.find(h));
        }
        int max_h = *height.rbegin();
        // when height changes!
        if (max_h != prev_height) {
          prev_height = max_h;
          ans.push_back({p[i].first, max_h});
        }
      }
      return ans;
    }
};
// @lc code=end
// int main() {
//   vector<vector<int>> building = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
//   Solution sol;
//   sol.getSkyline(building);
// }

