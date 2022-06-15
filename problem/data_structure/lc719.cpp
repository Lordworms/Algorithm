/*
    题意：数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。

    给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。返回 所有数对距离中 第 k 小的数对距离。

    题解：
        二分+双指针
        每次遇见统计第k大，第k小，考虑使用二分，这里给出一个统计区间满足大于/小于某个数的数对数量的板子，也就是先排序，然后固定一端，另一端
        来++，每次固定一端后进行计算加和，
        如果当前区间内的数对的差小于k的话，那么说明给的区间小了，那么需要增大区间l=m+1; 
        否则说明区间大了，r=m-1
        由于二分查找最终会逼近最左的那个解，所以我们返回l即可
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums.front(),n=nums.size();
        while(l<=r)
        {
            int m=(l+r)>>1;
            int count=0;
            for(int i=0,j=0;j<n;++j)
            {
                while(abs(nums[j]-nums[i])>m)++i;
                count+=(j-i);
            }
            if(count<k)
            {
                l=m+1;
            }   
            else
            {
                r=m-1;
            } 
        }
        return l;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>nums={1,6,1};
  cout<<sol.smallestDistancePair(nums,3);
  return 0;
}