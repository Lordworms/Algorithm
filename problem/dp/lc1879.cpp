/*
    题面：给你两个整数数组 nums1 和 nums2 ，它们长度都为 n 。

        两个数组的 异或值之和 为 (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) （下标从 0 开始）。
        比方说，[1,2,3] 和 [3,2,1] 的 异或值之和 等于 (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4 。
        请你将 nums2 中的元素重新排列，使得 异或值之和 最小 。
        请你返回重新排列之后的 异或值之和 。



    题解：两种做法，第一种可以将其转化为一个km问题，即二分图的最大权匹配
         第二种用状态压缩dp来解决
         我们用二进制数表示在nums2中某个数是否被选用，那么容易得出我们的状态转移方程
         其中dp的下标表示前c个数字被选用的情况
         dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i])
         注意打括号的问题！

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>dp(1<<n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<(1<<n);++i)
        {
            int c=__builtin_popcount(i);
            for(int j=0;j<n;++j)
            {
                if((i&(1<<j))==0)
                {
                    int k=i|(1<<j);
                    dp[k]=min(dp[k],dp[i]+nums2[c]^nums1[j]);
                }
            }
        }
        return dp.back();
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}