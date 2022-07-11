/*
题意：给你一个整数数组 nums 和一个整数 threshold 。找到长度为 k 的 nums 子数组，满足数组中 每个 元素都 大于 threshold / k 。
请你返回满足要求的 任意 子数组的 大小 。如果没有这样的子数组,返回-1 。子数组 是数组中一段连续非空的元素序列。
题解：两种方式可以解决这个问题
    1.并查集(joint search set)
    2.单调栈
        对每一个元素，把它当作数组中最小的元素，枚举其向右可以延伸到哪里，向左可以延伸到哪里，之后枚举左右边界，当前元素大于
        threshold/(right[i]-left[i]+1)那么就是一个解
    
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<int>left(n,0),right(n,0);
        stack<int>s;
        for(int i=0;i<n;++i)
        {
            while(s.size()&&nums[i]<nums[s.top()])
            {
                right[s.top()]=i-1;
                s.pop();  
            }
            s.push(i);
        }
        while(s.size()){right[s.top()]=n-1;s.pop();}
        for(int i=n-1;i>=0;--i)
        {
            while(s.size()&&nums[i]<nums[s.top()])
            {
                left[s.top()]=i+1;
                s.pop();
            }
            s.push(i);
        }
        while(s.size()){left[s.top()]=0;s.pop();}
        for(int i=0;i<n;++i)
        {
            int k=right[i]-left[i]+1;
            if(nums[i]>threshold/k)
            {
                return k;
            }
        }
        return -1;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>nums={1,3,4,3,1};
  sol.validSubarraySize(nums,6);
  return 0;
}