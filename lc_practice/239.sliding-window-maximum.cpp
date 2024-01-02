/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      deque<int> q;
      vector<int> ans;
      for (int i = 0; i < n; ++i) {
        while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
        q.push_back(i);
        while (q.size() && q.back() - q.front() >= k) q.pop_front();
        if (i >= k - 1) {
          ans.push_back(nums[q.front()]);  
        }  
      }
      return ans;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> a = {1,3,-1,-3,5,3,6,7};
//   sol.maxSlidingWindow(a, 3);
//   return 1;
// }
