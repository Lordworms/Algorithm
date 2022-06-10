/*
    题面：给你一个整数数组 nums 和一个目标值 goal 。

        你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。

        返回 abs(sum - goal) 可能的 最小值 。
    题解：
        状压dp 我们首先处理出左半部分的区间和以及右半部分的区间和（状态压缩）
        之后我们把这两个数组进行排序，排序后我们用双指针的方式求最优解
        注意每次状压计算后我们都要break，这是因为我们不需要
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int lpart=n/2,rpart=n-n/2;
        int ans=INT_MAX;
        vector<int>lsum(1<<lpart,0),rsum(1<<rpart,0);
        for(int i=0;i<(1<<(lpart));++i)
        {
            for(int k=0;k<lpart;++k)
            {
                if((i&(1<<k))==0)continue;
                lsum[i]=lsum[i-(1<<k)]+nums[k];
                break;
            }
        }
        for(int i=0;i<(1<<rpart);++i)
        {
            for(int k=0;k<rpart;++k)
            {
                if((i&(1<<k))==0)continue;
                rsum[i]=rsum[i-(1<<k)]+nums[k+lpart];
                break;
            }
        }
        sort(lsum.begin(),lsum.end());
        sort(rsum.begin(),rsum.end());
        for(int x:lsum)ans=min(ans,abs(x-goal));
        for(int x:rsum)ans=min(ans,abs(x-goal));
        int l=0,r=rsum.size()-1;
        while(l<lsum.size()&&r>=0)
        {
            int sum=lsum[l]+rsum[r];
            ans=min(ans,abs(sum-goal));
            if(sum>goal)
            {
                --r;
            }
            else
            {
                ++l;
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
  vector<int>nums={1556913,-259675,-7667451,-4380629,-4643857,-1436369,7695949,-4357992,-842512,-118463};
  cout<<sol.minAbsDifference(nums,-9681425);
  return 0;
}