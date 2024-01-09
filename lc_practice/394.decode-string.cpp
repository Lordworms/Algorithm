/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string decodeString(string s) {
    string num, str, ans;
    char cur;
    int mod = 0;
    vector<string> st, ss;
    vector<int> cnt, ans_cnt;
    for (int i = 0; i < s.size(); ++i) {
      if (isalpha(s[i]) || s[i] == '[') {
        st.push_back(string() + s[i]);
      } else if (s[i] >= '0' && s[i] <= '9') {
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
          num.push_back(s[i++]);
        }
        cnt.push_back(atoi(num.c_str()));
        num = "";
        --i;
      } else if (s[i] == ']') {
        while (st.size()) {
          auto c = st.back();
          st.pop_back();
          if (c == "[") {
            break;
          }
          str = c + str;
        }
        int total = cnt.back();
        cnt.pop_back();
        string cur_str;
        for (int i = 0; i < total; ++i) {
          cur_str += str;
        }
        str = "";
        st.push_back(cur_str);
      }
    }
    while (!st.empty()) {
      ans = st.back() + ans;
      st.pop_back();
    }
    return ans;
  }
};
// @lc code=end
int main() {
  Solution sol;
  cout << sol.decodeString("3[a]2[bc]") << '\n';
}
