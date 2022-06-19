/*
    题意：给定一个正整数 n ，返回范围在 [0, n] 都非负整数中，其二进制表示不包含 连续的 1 的个数。
    题解:数字的范围在1e9，所以不可能遍历n来做,这是一道数位dp的板子题
        另dp[i]表示在以0为根的0-1字典树中，其高度为i-1没有连续1的数字的个数
        dp[i]=dp[i-1]+dp[i-2]其中dp[i-1]表示其左子树，dp[i-2]表示其右子树的左子树
        然后我们倒序遍历，每次
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>h(nums.size()+1,0);
        for(int i=1;i<=nums.size();++i)h[i]=h[i-1]+nums[i-1];
        int ans=INT_MAX;
        q.push_back(0);
        for(int i=1;i<=nums.size();++i)
        {
            //先pop
            while(!q.empty()&&h[q.back()]>h[i])q.pop_back();
            while(!q.empty()&&h[i]-h[q.front()]>=k){ans=min(ans,i-q.back());q.pop_front();}
            q.push_back(i);
        }
        return ans==INT_MAX?-1:ans;
   }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution Sol;
  vector<int>num={};
  cout<<Sol.shortestSubarray()
  return 0;
}