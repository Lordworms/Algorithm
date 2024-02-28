/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> a(26);
        for (int i = 0; i < tasks.size(); ++i) {
            a[tasks[i] - 'A']++;
        }
        sort(a.begin(), a.end());
        int min_len = (n + 1) * (a[25] - 1) + 1;
        for (int i = 24; i >= 0; --i) {
          if (a[i] == a[25]) {
            ++min_len;
          }
        }
        return max((size_t)min_len, tasks.size());
    }
};
// @lc code=end

