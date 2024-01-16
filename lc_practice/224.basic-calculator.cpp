/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  #define isnumber(x) (x >= '0' && x <= '9')
  int calculate(string s) {
    vector<int> ops;
    int sign = 1;
    ops.push_back(1);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '+') {
        sign = ops.back();
      } else if (s[i] == '-') {
        sign = -ops.back();
      } else if (s[i] == '(') {
        ops.push_back(sign);
      } else if (s[i] == ')') {
        ops.pop_back();
      } else if (isnumber(s[i])){
        string num = "";
        while (i < s.size() && isnumber(s[i])) num += s[i++];
        --i;
        ans += sign * atoi(num.c_str());
      }
    }
    return ans;
  }
};
// @lc code=end
// int main() {
//   Solution sol;
//   sol.calculate("(1+(4+5+2)-3)+(6+8)");
// }
