/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void push_down(vector<int> &nums, int i, int lim) {
      while (i < lim) {
        int nxt = i * 2 + 1;
        if (nxt >= lim) break;
        if (nxt < lim - 1 && nums[nxt + 1] < nums[nxt]) ++nxt;
        if (nums[i] > nums[nxt]) swap(nums[i], nums[nxt]);
        i = nxt;
      }
    }
    void push_up(vector<int> &nums, int i) {
      while (i) {
        int par = (i - 1) >> 1;
        if (nums[i] < nums[par]) {
          swap(nums[i], nums[par]);
        }
        i = par;
      }
    }
    int findKthLargest(vector<int>& nums, int k) {
      for (int i = 0; i < k; ++i) {
        push_up(nums, i);
      }
      for (int i = k; i < nums.size(); ++i) {
        if (nums[i] > nums[0]) {
          swap(nums[i], nums[0]);
          push_down(nums, 0, k);
        }
      }
      return nums[0];
    }
};
// @lc code=end
// int main() {
//     vector<int> a = {3,2,1,5,6,4};
//     Solution sol;
//     sol.findKthLargest(a, 2);
// }
