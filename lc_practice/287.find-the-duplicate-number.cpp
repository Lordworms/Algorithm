/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
        suppose the duplicated number is k
        then for [1, k - 1] cnt[i] <= i
        else cnt[i] > i
        we have to find the first element that cnt[i] > i
    
    */
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1, ans = -1;
      while (l <= r) {
        int m = (l + r) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
          cnt += nums[i] <= m;
        }
        if (cnt > m) {
          ans = m;
          r = m - 1;    
        } else {
          l = m + 1;
        }
      } 
      return ans;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {1, 3, 4, 2, 2};
//   sol.findDuplicate(a);
// }
