#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        vector<int>q(n+1,0);
        int l=0,r=-1;
        for(int i=0;i<n;++i)
        {
            while(l<=r&&nums[i]>nums[q[r]])--r;
            q[++r]=i;
            if(i>=k-1&&i-q[l]+1>k)++l;
            if(i>=k-1)ans.push_back(nums[q[l]]);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>arr={7,2,4};
  sol.maxSlidingWindow(arr,2);
  return 0;
}