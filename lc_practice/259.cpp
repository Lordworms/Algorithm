class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int ans = 0;
      int l, r;
      for (int i = 0; i < n - 2; ++i) {
        l = i + 1, r = n - 1;
        while (l < r) {
          if (nums[l] + nums[r] < target - nums[i]) {
            ans += r - l;
            ++l;
          } else {
            --r;
          }    
        }
      }
      return ans;
    }
};