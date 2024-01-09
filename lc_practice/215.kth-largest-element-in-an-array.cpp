/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    void push_up(vector<int> &nums, int i) {
      while (i && nums[i] < nums[(i - 1)>> 1]) {
        swap(nums[i], nums[(i - 1) >> 1]);
        i = (i - 1) >> 1;
      }  
    }
    void push_down(vector<int> &nums, int i, int lim) {
      while ((i << 1 | 1) < lim) {
        int cur = i << 1 | 1;
        if (cur + 1 < lim && nums[cur] > nums[cur + 1]) {
          ++cur;
        }
        if (nums[cur] > nums[i]) {
          break;  
        }
        swap(nums[cur], nums[i]);
        i = cur;
      }    
    }
    int findKthLargest(vector<int>& nums, int k) {
      for (int i = 0; i < k; ++i) {
        push_up(nums, i);
      }        
      for (int i = k; i < nums.size(); ++i) {
        if (nums[i] > nums[0]) {
          swap(nums[0], nums[i]);
          push_down(nums, 0, k);  
        }
      }
      return nums[0];
    }
};
// @lc code=end

