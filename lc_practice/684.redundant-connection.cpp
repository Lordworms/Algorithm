/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> f(n + 1);
        iota(f.begin(), f.end(), 0);
        function<int(int)> find = [&] (int x) {
            return x == f[x] ? x : find(f[x]);
        };
        auto add = [&] (int x, int y) {
            x = find(x), y = find(y);
            if (x != y) {
                f[y] = x;
            }
        };
        for (auto e : edges) {
            int x = e[0], y = e[1];
            if (find(x) == find(y)) {
                return e;
            }
            add(x, y);
        }
        return vector<int>();
    }
};
// @lc code=end

