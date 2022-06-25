/*
题意：给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
题解：
    1.dp暴力，这里需要注意，因为是最长公共前缀，所以我们这里需要从尾到头进行
    dp[i][j]表示nums1和nums2的最长公共前缀
    但是这种方式有太多不需要的比较（类似kmp）
    2.使用字符串哈希的方式来求解
        先清楚一点，对于h[0:len]已知，那么h[1:len+1]=(h[0:len]-nums[0]*pow(base,len-1))*base+s[len];
        记得P=131,mod=1e9+7
        因此,我们对于每一个长度进行二分，计算A数组所有len长度的哈希值，然后计算B数组的所有len长度的哈希值，之后set.count判断即可

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLength_worse(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ans=INT_MIN;
        for(int i=m-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                dp[i][j]=nums1[i]==nums2[j]?dp[i+1][j+1]:0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
    
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution Sol;
  vector<int>nums1={1,2,3,2,1};
  vector<int>nums2={3,2,1,4,7};
  Sol.findLength(nums1,nums2);
  return 0;
}