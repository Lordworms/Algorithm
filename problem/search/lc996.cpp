/*
给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。

返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int>tmp;
    int ans=0;
    int n;
    vector<bool>used;
public:
    void dfs(vector<int>& nums,int now)
    {
        if(now==n)
        {
            ans++;
            return;
        }
        for(int i=0;i<n;++i)
        {
            if(i&&nums[i-1]==nums[i]&&!used[i-1])continue;//会重复
            if(!used[i])
            {
                if(now==0||sqrt(nums[i]+tmp[now-1])-(int)sqrt(nums[i]+tmp[now-1])==0)
                {
                    used[i]=true;
                    tmp.push_back(nums[i]);
                    dfs(nums,now+1);
                    tmp.pop_back();
                    used[i]=false;
                }
            }
        }

    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used.resize(12,false);
        n=nums.size();
        dfs(nums,0);
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    Solution sol;
    vector<int>nums={1,17,8};
    sol.numSquarefulPerms(nums);
  return 0;
}