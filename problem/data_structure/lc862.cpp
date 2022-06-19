/*
    题意：给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。
         子数组 是数组中 连续 的一部分。
    题解：
        1.由于这道题的数据有负数，所以不能用双指针的滑动窗口来解
        2.考虑用单调栈的思想来做,我们维护一个递增的前缀和
        3.使用双端队列
        考虑更新的策略：
            设当前为i，如果当前的sum[q.back()]>sum[i]表示[q.back(),i]区间的和为负数，那么对于未来的某个sum[k]来说，sum[q.back()]不可能为最优解，因为
            我们这里有了sum[i],这也就表明,可以直接pop_back()了
            另外，我们可以顺势从队首更新
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using ll=long long;
        deque<int>q;
        vector<ll>h(nums.size()+1,0);
        for(int i=1;i<=nums.size();++i)h[i]=h[i-1]+nums[i-1];
        int ans=INT_MAX;
        for(int i=0;i<=nums.size();++i)
        {
            while(!q.empty()&&(h[i]-h[q.front()])>=k)
            {
                ans=min(ans,i-q.front());
                q.pop_front();
            }
            //先pop
            while(!q.empty()&&h[q.back()]>=h[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans==INT_MAX?-1:ans;
   }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>nums={-28,81,-20,28,-29};
  Solution sol;
  cout<<sol.shortestSubarray(nums,89);
  return 0;
}