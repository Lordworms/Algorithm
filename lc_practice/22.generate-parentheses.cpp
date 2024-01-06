/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int n;
    vector<string> ans;
public:
    /*
        two rules:
        I. left should be more than right
        II. I is the only rule
    */
    void dfs(string s, int left, int right) {
      if (s.size() == 2 * n) {
        ans.push_back(s);
      }
      if (left) {
        dfs(s + '(', left - 1, right);  
      }
      if (right && right > left) {
        dfs(s + ')', left, right - 1);
      }
    }
    vector<string> generateParenthesis(int n) {
      this->n = n;
      dfs("", n, n);
      return ans;
    }
};
// @lc code=end
int main() {
  Solution sol;
  sol.generateParenthesis(3);
}

