/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size(), m = nums2.size();
      if (n > m) {
        return findMedianSortedArrays(nums2, nums1);
      } 
      int l = 0, r = 2 * n;
      int maxl1, maxl2, minr1, minr2;
      while (l <= r) {
        int c1 = (l + r) >> 1;
        int c2 = m + n - c1;
        maxl1 = (c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2]) ;
        maxl2 = (c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2] );
        minr1 = (c1 == 2 * n? INT_MAX : nums1[c1 / 2]);
        minr2 = (c2 == 2 * m? INT_MAX : nums2[c2 / 2]);
        if (maxl1 > minr2) {
          r = c1 - 1;
        } else if (maxl2 > minr1) {
          l = c1 + 1;
        } else {
          break;
        }
      }
      return (max(maxl1, maxl2) + min(minr1, minr2)) / 2.0;
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   vector<int> nums1 = {1, 3}, nums2 = {2};
//   sol.findMedianSortedArrays(nums1, nums2);
// }

