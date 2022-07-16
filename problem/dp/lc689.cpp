/*
题意：  
    给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k 、互不重叠、且全部数字和（3 * k 项）最大的子数组，并返回这三个子数组。
    以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0 开始）。如果有多个结果，返回字典序最小的一个。
题解：
    序列dp题，另dp[i][j]为前i个数字中，分出j个子序列的最值
    剩下的很简单


*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=unsigned long long;
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>ans;
        if(3*k>nums.size())return ans;
        int n=nums.size();
        vector<ll>sum(n+1,0);
        for(int i=1;i<=n;++i)sum[i]=sum[i-1]+nums[i-1];
        vector<vector<ll>>dp(n+1,vector<ll>(4,0));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<4;++j)
            {
                if(i<k)continue;
                ll now=dp[i-k][j-1]+sum[i]-sum[i-k];
                if(now>dp[i-1][j])
                {
                    dp[i][j]=now;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int now_size=3;
        for(int i=n-1;i>=0;--i)
        {
            if(dp[i][now_size]!=dp[i+1][now_size])
            {
                --now_size;
                i-=(k-1);
                ans.push_back(i);
            }
            if(!now_size)
            {
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>arr={1,2,1,2,6,7,5,1};
  sol.maxSumOfThreeSubarrays(arr,2);
  return 0;
}