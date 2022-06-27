/*
题意：给你一个整数数组 nums​​​ 和一个整数 k​​​​​ 。区间 [left, right]（left <= right）的 异或结果 是对下标位于 left 和 right（包括 left 和 right ）之间所有元素进行 XOR 运算的结果：nums[left] XOR nums[left+1] XOR ... XOR nums[right] 。

返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等于零。
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int INF=1<<10;
        int n=nums.size();
        vector<int>dp(INF,k+1);
        for(int i=0;i+k<n;++i)
        {
            for(int j=0;j<k;++j)
            {
                
            }
        }
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}