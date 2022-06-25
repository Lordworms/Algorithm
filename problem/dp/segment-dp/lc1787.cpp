/*
题意：给你一个整数数组 nums​​​ 和一个整数 k​​​​​ 。区间 [left, right]（left <= right）的 异或结果 是对下标位于 left 和 right（包括 left 和 right ）之间所有元素进行 XOR 运算的结果：nums[left] XOR nums[left+1] XOR ... XOR nums[right] 。

返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等于零。
题解：首先，由于异或的性质，我们很容易得知，arr[i]=arr[i+k]=arr[i+2*k]=...arr[i+nk]
     我们把对应的i视为一个组，然后我们来考虑
     转移方程为dp[i][val]=min(dp[i-1])+size(i)//对于不在该组中的值
             dp[i][val]=min(dp[i-1])+size(i)-group[i][num]//用该组中有的数来做
    
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int MAXN=1<<10;
        const int INF=0x3f3f3f3f;
        vector<int>dp(MAXN,INF);//设成inf！
        vector<unordered_map<int,int>>group(k);
        vector<int>size(k,0);//别忘了，不能直接用unordered_map的size，不对！
        dp[0]=0;
        for(int i=0;i<k;++i)
        {
            for(int j=i;j<nums.size();j+=k)
            {
                group[i][nums[j]]++;
                size[i]++;
            }
        }
        for(int i=0;i<k;++i)
        {
            int minValue=*min_element(dp.begin(),dp.end());
            vector<int>tmp(MAXN,minValue+size[i]);
            for(int j=0;j<MAXN;++j)
            {
                if(dp[j]==INF)continue;
                for(auto[num,freq]:group[i])
                {
                    int p=j^num;
                    tmp[p]=min(tmp[p],(int)(dp[j]+size[i]-freq));
                }
            }
            dp=move(tmp);
        }
        return dp[0];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
return 0;
}