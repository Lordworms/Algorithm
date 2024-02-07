/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;
    vector<int> S(10), G(10);
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++bulls;
        continue;
      }
      S[secret[i] - '0']++;
      G[guess[i] - '0']++;
    }
    for (int i = 0; i < 10; ++i) {
        cows += min(S[i], G[i]);
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
  }
};
// @lc code=end
