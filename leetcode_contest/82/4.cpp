/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int l=0,r=0,minn=nums[0];
        int ans=0;
        while(r<nums.size())
        {
            if(nums[r]<threshold/(r-l+1))
            {
                ++r;
                ans=r-l+1;
            }
            else 
            {
                ++r;
                minn
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  return 0;
}