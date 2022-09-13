#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int convertArray(vector<int>& nums) {//有斜率优化的版本

    }
    int convertArray_1(vector<int>& nums) {//无斜率优化的版本
        vector<vector<int>>dp;
        vector<int>vec(nums);
        sort(vec.begin(),vec.end());
        int n=nums.size(),MAXN=1010;
        int ans=INT_MAX,LIM=*max_element(nums.begin(),nums.end());
        dp.assign(n,vector<int>(n+1,INT_MAX));
        for(int j=0;j<n;++j)dp[0][j]=abs(nums[0]-vec[j]);
        //递增
        for(int i=1;i<n;++i)
        {
            int value=dp[i-1][0];
            for(int j=0;j<n;++j)
            {
                value=min(value,dp[i-1][j]);
                dp[i][j]=min(dp[i][j],value+abs(nums[i]-vec[j]));
            }
        }
        ans=min(ans,*min_element(dp[n-1].begin(),dp[n-1].end()));
        dp.assign(n,vector<int>(n+1,INT_MAX));
        reverse(vec.begin(),vec.end());
        for(int j=0;j<n;++j)dp[0][j]=abs(nums[0]-vec[j]);
        //递减
        for(int i=1;i<n;++i)
        {
            int value=dp[i-1][0];
            for(int j=0;j<n;++j)
            {
                value=min(value,dp[i-1][j]);
                dp[i][j]=min(dp[i][j],value+abs(nums[i]-vec[j]));
            }
        }
        ans=min(ans,*min_element(dp[n-1].begin(),dp[n-1].end()));
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>arr={3,2,4,5,0};
  sol.convertArray(arr);
  return 0;
}