/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int n) {
      vector<vector<int>> ans;
      ans.push_back({1});
      if (n == 1) {
        return ans;
      }  
      ans.push_back({1,1});
      if (n == 2) {
        return ans;
      }
      for (int i = 3; i <= n; ++i) {
        vector<int> tmp;
        for (int j = 0; j < i; ++j) {
          if (j == 0 || j == i - 1) {
            tmp.push_back(1);   
            continue; 
          } 
          tmp.push_back(ans.back()[j - 1] + ans.back()[j]);  
        }
        ans.push_back(tmp);
      }
      return ans;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.generate(5);
// }

