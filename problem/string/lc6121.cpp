/*
    这题有很深的意义，我们不需要直接遍历string进行sort，相反的，我们创建一个idx数组，来代替我们进行遍历

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int len=nums[0].size(),n=nums.size();
        for(auto& q:queries)
        {
            int k=q[1];
            string S[100];
            for(int i=0;i<n;++i)S[i]=nums[i].substr(len-k);
            int arr[n];
            iota(arr,arr+n,0);
            sort(arr,arr+n,[&](int a,int b){if(S[a]!=S[b])return S[a]<S[b];return a<b;});
            ans.push_back(arr[q[0]-1]);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>nums={3,2,6,2,35,5,35,2,5,8,7,3,4};
  vector<int>nums1={105,70,70,175,105,105,105};
  Solution sol;
  sol.smallestTrimmedNumbers(nums,nums1);
  return 0;
}